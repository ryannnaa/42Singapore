/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:55:26 by tiatan            #+#    #+#             */
/*   Updated: 2024/10/30 13:58:33 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_struct(int argc, char **argv, char **envp, t_struct *p_struct)
{
	p_struct->envp = envp;
	p_struct->argv = argv;
	p_struct->paths = NULL;
	p_struct->cmd_path = NULL;
	p_struct->cmd_args = NULL;
	p_struct->argc = argc;
	p_struct->in_fd = -1;
	p_struct->out_fd = -1;
	p_struct->new_fd[0] = -1;
	p_struct->new_fd[1] = -1;
	p_struct->old_fd[0] = -1;
	p_struct->old_fd[1] = -1;
	if (ft_strncmp(argv[1], "here_doc", 9))
		p_struct->heredoc = 0;
	else
		p_struct->heredoc = 1;
	p_struct->cmd_count = argc - 3 - p_struct->heredoc;
	p_struct->index = 0;
	p_struct->i = 0;
	p_struct->pid = 0;
}

static void	create_heredoc(t_struct *p_struct)
{
	int		temp_fd;
	char	*line;

	temp_fd = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (temp_fd == -1)
		ft_putstr_fd("Error: Unable to create heredoc\n", 2);
	line = NULL;
	while (1)
	{
		ft_putstr_fd("Type Text >", 1);
		line = get_next_line(0);
		if (line == NULL)
			break ;
		if (!ft_strncmp(line, p_struct->argv[2], ft_strlen(p_struct->argv[2])))
			break ;
		else
			ft_putstr_fd(line, temp_fd);
		free(line);
	}
	free(line);
	close(temp_fd);
}

static void	open_fd(t_struct *p_struct)
{
	if (p_struct->heredoc != 0)
	{
		create_heredoc(p_struct);
		p_struct->in_fd = open(p_struct->argv[1], O_RDONLY);
		p_struct->out_fd = open(p_struct->argv[p_struct->argc - 1],
				O_CREAT | O_WRONLY | O_APPEND, 0644);
	}
	else
	{
		p_struct->in_fd = open(p_struct->argv[1], O_RDONLY);
		p_struct->out_fd = open(p_struct->argv[p_struct->argc - 1],
				O_CREAT | O_WRONLY | O_TRUNC, 0644);
	}
	if (p_struct->in_fd == -1)
	{
		ft_putstr_fd("Error: Permission denied for infile\n", 2);
		p_struct->in_fd = open("/dev/NULL", O_RDONLY);
	}
	if (p_struct->out_fd == -1)
	{
		ft_putstr_fd("Error: Permission denied for outfile\n", 2);
		p_struct->out_fd = open("/dev/NULL", O_WRONLY);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_struct	*p_struct;
	int			exit;

	if (argc != 5)
		return (ft_putstr_fd("Error: Invalid number of arguments\n", 2), 1);
	if (!(ft_strncmp(argv[1], "here_doc", 9)))
	{
		if (argc < 6)
			return (ft_putstr_fd("Error: Invalid number of arguments\n", 2), 1);
	}
	p_struct = malloc(sizeof(t_struct));
	if (!p_struct)
		return (1);
	init_struct(argc, argv, envp, p_struct);
	open_fd(p_struct);
	exit = pipe_args(p_struct);
	free_all(p_struct);
	return (exit);
}
