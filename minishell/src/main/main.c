/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:50:41 by ylai              #+#    #+#             */
/*   Updated: 2025/03/18 17:04:03 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_shell	*shell;
	int		status;

	(void)argv;
	if (!check_arg(argc))
		return (0);
	shell = malloc(sizeof(t_shell));
	if (!shell)
		return (-1);
	init_shell(shell, env);
	setup_env(&shell->env_ll, env, shell);
	g_sigint = 0;
	init_attr(shell->attr, &shell->env_ll);
	shell_loop(shell);
	free_env(&shell->env_ll);
	if (shell->attr)
		free(shell->attr);
	status = shell->exit;
	free(shell);
	rl_clear_history();
	return (status);
}
