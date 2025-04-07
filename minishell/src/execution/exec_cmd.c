/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:05:35 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/19 19:09:39 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	handle_parent(int pid, t_shell *shell)
{
	int		term_sig;

	term_sig = 0;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	waitpid(pid, &shell->exit, 0);
	if (WIFEXITED(shell->exit))
		shell->exit = WEXITSTATUS(shell->exit);
	else if (WIFSIGNALED(shell->exit))
	{
		term_sig = WTERMSIG(shell->exit);
		shell->exit = 128 + term_sig;
		if (term_sig == SIGQUIT)
			write(STDOUT_FILENO, "Quit (core dumped)\n", 19);
		else if (term_sig == SIGINT)
			write(STDOUT_FILENO, "\n", 1);
	}
	setup_sig_interactive();
}

void	child_ve(t_ast *node, t_shell *shell)
{
	char	**env;
	char	*path;
	t_exec	exec;

	exec.cmd = NULL;
	exec.paths = NULL;
	extract_paths(&exec, shell->env_ll);
	path = get_env(shell->env_ll, "PATH");
	env = env_arr(shell->env_ll);
	check_path(&exec, node);
	if (path != NULL && (exec.cmd[0] == '/' || exec.cmd[0] == '.'))
		execve(exec.cmd, node->args, env);
	else if (path == NULL)
		execve(exec.cmd, node->args, env);
	free_2d(env);
	if (exec.paths)
		free_2d(exec.paths);
	if (exec.cmd)
		free(exec.cmd);
	exec_err(node, shell);
}

void	exec_ve(t_ast *node, t_shell *shell)
{
	int		pid;

	pid = fork();
	if (pid == -1)
		ft_putstr_fd("Error: Failed to fork\n", 2);
	else if (pid == 0)
	{
		setup_sig_exec();
		close(shell->std_in);
		close(shell->std_out);
		close_rd(shell->tree);
		if (node->args && node->args[0])
			child_ve(node, shell);
		else
			exit(shell->exit);
	}
	else
		handle_parent(pid, shell);
}

void	what_exec(t_ast *node, t_shell *shell)
{
	if (ft_strncmp(node->args[0], "echo", 5) == 0)
		shell->exit = bi_echo(node->args);
	else if (ft_strncmp(node->args[0], "cd", 3) == 0)
		shell->exit = bi_cd(&shell->env_ll, shell, node->args);
	else if (ft_strncmp(node->args[0], "pwd", 4) == 0)
		shell->exit = bi_pwd();
	else if (ft_strncmp(node->args[0], "export", 7) == 0)
		shell->exit = bi_export(&shell->env_ll, shell, node->args);
	else if (ft_strncmp(node->args[0], "unset", 6) == 0)
		shell->exit = bi_unset(&shell->env_ll, node->args);
	else if (ft_strncmp(node->args[0], "env", 4) == 0)
		shell->exit = bi_env(&shell->env_ll);
	else if (ft_strncmp(node->args[0], "exit", 5) == 0)
		bi_exit(shell, node->args);
	else if (ft_strncmp(node->args[0], ".", 2) == 0)
		bi_dot(node, shell);
	else
		exec_ve(node, shell);
}

void	exec_cmd(t_ast *node, t_shell *shell)
{
	shell->std_in = dup(STDIN_FILENO);
	shell->std_out = dup(STDOUT_FILENO);
	if (shell->std_in < 0 || shell->std_out < 0)
	{
		ft_putstr_fd("Error: Failed to save stdout or stdin\n", 2);
		exit(-1);
	}
	if (exec_rd(node->rd, shell) == 0 && node->args[0])
		what_exec(node, shell);
	else if (node->args[0] == NULL)
		shell->exit = 0;
	if (dup2(shell->std_in, STDIN_FILENO) < 0)
	{
		ft_putstr_fd("Error: Failed to restore stdin\n", 2);
		exit(-1);
	}
	close(shell->std_in);
	if (dup2(shell->std_out, STDOUT_FILENO) < 0)
	{
		ft_putstr_fd("Error: Failed to restore stdout\n", 2);
		exit(-1);
	}
	close(shell->std_out);
}
