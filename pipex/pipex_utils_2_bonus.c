/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:22:07 by tiatan            #+#    #+#             */
/*   Updated: 2024/10/30 13:52:41 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	redirect(int fd_input, int fd_output, t_struct *p_struct)
{
	if (dup2(fd_input, STDIN_FILENO) == -1)
	{
		free_all(p_struct);
		exit(1);
	}
	if (dup2(fd_output, STDOUT_FILENO) == -1)
	{
		free_all(p_struct);
		exit(1);
	}
}

void	redirect_rw(t_struct *p_struct)
{
	if (p_struct->index == 0)
		redirect(p_struct->in_fd, p_struct->new_fd[1], p_struct);
	else if (p_struct->index == p_struct->cmd_count - 1)
		redirect(p_struct->old_fd[0], p_struct->out_fd, p_struct);
	else
		redirect(p_struct->old_fd[0], p_struct->new_fd[1], p_struct);
}

void	extract_paths(t_struct *p_struct)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	while ((p_struct->envp[i]) != NULL)
	{
		if (ft_strncmp(p_struct->envp[i], "PATH=", 5) == 0)
			temp = p_struct->envp[i];
		i++;
	}
	if (temp)
		p_struct->paths = ft_split_append(temp + 5, ':');
}

void	check_path(t_struct *p_struct)
{
	p_struct->cmd_args = ft_split(p_struct->argv[2 + p_struct->index
			+ p_struct->heredoc], ' ');
	if (!p_struct->cmd_args)
		ft_putstr_fd("Error: Unable to split arguments\n", 2);
	if (p_struct->paths)
	{
		while (p_struct->paths[p_struct->i])
		{
			p_struct->cmd_path = ft_strjoin(p_struct->paths[p_struct->i],
					p_struct->cmd_args[0]);
			if (!p_struct->cmd_path)
				ft_putstr_fd("Error: Path creation issue\n", 2);
			if (access(p_struct->cmd_path, F_OK) == 0)
				break ;
			free(p_struct->cmd_path);
			p_struct->cmd_path = NULL;
			p_struct->i++;
		}
	}
	if (!p_struct->cmd_path)
		p_struct->cmd_path = ft_strdup(p_struct->argv[2 + p_struct->index
				+ p_struct->heredoc]);
}

void	execute(t_struct *p_struct)
{
	if (p_struct->cmd_args[0][0] == '.' && p_struct->cmd_args[0][1] == '/')
	{
		ft_putstr_fd("Error: No such file or directory\n", 2);
		free_all(p_struct);
		exit(127);
	}
	if (execve(p_struct->cmd_path, p_struct->cmd_args, p_struct->envp) == -1)
	{
		if (errno == EACCES)
		{
			ft_putstr_fd("Error: Permission denied\n", 2);
			free_all(p_struct);
			exit(126);
		}
		ft_putstr_fd("Error: Command not found\n", 2);
		free_all(p_struct);
		exit(127);
	}
}
