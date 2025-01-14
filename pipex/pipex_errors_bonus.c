/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:26:03 by tiatan            #+#    #+#             */
/*   Updated: 2024/10/17 14:44:05 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_2d(char **memory)
{
	size_t	i;

	i = 0;
	while (memory[i])
	{
		free(memory[i]);
		i++;
	}
	free(memory);
	memory = NULL;
}

void	clean_struct(t_struct *p_struct)
{
	if (p_struct->in_fd != -1)
		close(p_struct->in_fd);
	if (p_struct->out_fd != -1)
		close(p_struct->out_fd);
	if (p_struct->new_fd[0] != -1)
		close(p_struct->new_fd[0]);
	if (p_struct->new_fd[1] != -1)
		close(p_struct->new_fd[1]);
	if (p_struct->old_fd[0] != -1)
		close(p_struct->old_fd[0]);
	if (p_struct->old_fd[1] != -1)
		close(p_struct->old_fd[1]);
	if (p_struct->heredoc == 1)
		unlink("here_doc");
	if (p_struct->cmd_path != NULL)
		free(p_struct->cmd_path);
	if (p_struct->cmd_args != NULL)
		free_2d(p_struct->cmd_args);
	if (p_struct->paths != NULL)
		free_2d(p_struct->paths);
}

void	free_all(t_struct *p_struct)
{
	if (p_struct)
	{
		clean_struct(p_struct);
		free(p_struct);
		p_struct = NULL;
	}
}

void	close_pipes(t_struct *p_struct)
{
	if (p_struct->new_fd[0] != -1)
		close(p_struct->new_fd[0]);
	if (p_struct->new_fd[1] != -1)
		close(p_struct->new_fd[1]);
	if (p_struct->old_fd[0] != -1)
		close(p_struct->old_fd[0]);
	if (p_struct->old_fd[1] != -1)
		close(p_struct->old_fd[1]);
}
