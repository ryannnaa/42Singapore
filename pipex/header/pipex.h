/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:44:13 by tiatan            #+#    #+#             */
/*   Updated: 2024/10/21 13:59:54 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf.h"
# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_struct
{
	char	**envp;
	char	**argv;
	char	**paths;
	char	*cmd_path;
	char	**cmd_args;
	int		argc;
	int		in_fd;
	int		out_fd;
	int		new_fd[2];
	int		old_fd[2];
	int		heredoc;
	int		cmd_count;
	int		index;
	int		i;
	pid_t	pid;
}			t_struct;

void		free_2d(char **memory);
void		free_all(t_struct *p_struct);
void		clean_struct(t_struct *p_struct);
void		close_pipes(t_struct *p_struct);
void		redirect_rw(t_struct *p_struct);
void		extract_paths(t_struct *p_struct);
void		check_path(t_struct *p_struct);
void		execute(t_struct *p_struct);
int			pipe_args(t_struct *p_struct);
int			main(int argc, char **argv, char **envp);

#endif