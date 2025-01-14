/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:17:39 by tiatan            #+#    #+#             */
/*   Updated: 2024/10/23 15:59:24 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	fork_it(t_struct *p_struct)
{
	p_struct->pid = fork();
	if (p_struct->pid == -1)
		return ;
	if (p_struct->pid == 0)
	{
		redirect_rw(p_struct);
		extract_paths(p_struct);
		check_path(p_struct);
		if (p_struct->old_fd[1] != -1)
			close(p_struct->old_fd[1]);
		if (p_struct->new_fd[0] != -1)
			close(p_struct->new_fd[0]);
		if (p_struct->in_fd != -1)
			close(p_struct->in_fd);
		if (p_struct->out_fd != -1)
			close(p_struct->out_fd);
		execute(p_struct);
	}
}

static int	parent_wait(t_struct *p_struct)
{
	int	exit_status;

	exit_status = 0;
	waitpid(p_struct->pid, &exit_status, 0);
	while (wait(NULL) > 0)
		;
	close_pipes(p_struct);
	return (WEXITSTATUS(exit_status));
}

int	pipe_args(t_struct *p_struct)
{
	int	wait_status;

	wait_status = 0;
	while (p_struct->index < p_struct->cmd_count)
	{
		if (p_struct->index < p_struct->cmd_count - 1)
		{
			if (pipe(p_struct->new_fd) == -1)
				return (-1);
		}
		fork_it(p_struct);
		if (p_struct->index > 0)
		{
			close(p_struct->old_fd[0]);
			close(p_struct->old_fd[1]);
		}
		if (p_struct->index < p_struct->cmd_count - 1)
		{
			p_struct->old_fd[0] = p_struct->new_fd[0];
			p_struct->old_fd[1] = p_struct->new_fd[1];
		}
		p_struct->index++;
	}
	wait_status = parent_wait(p_struct);
	return (wait_status);
}
