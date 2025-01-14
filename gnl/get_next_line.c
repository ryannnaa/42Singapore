/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:28:18 by tiatan            #+#    #+#             */
/*   Updated: 2024/08/29 21:55:38 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *buffer, char **stash)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		if (*stash && ft_strchr(*stash, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		buffer[bytes_read] = '\0';
		if (bytes_read == 0)
			break ;
		if (!*stash)
			*stash = ft_strdup("");
		temp = *stash;
		*stash = ft_strjoin(temp, buffer);
		free(temp);
		if (!*stash)
			return (NULL);
	}
	return (*stash);
}

static char	*get_line(char *line, char **stash)
{
	char	*temp;
	size_t	len;

	len = 0;
	while ((*stash)[len] != '\0' && (*stash)[len] != '\n')
		len++;
	if ((*stash)[len] == '\n')
		len++;
	line = ft_substr(*stash, 0, len);
	if (!line)
		return (NULL);
	temp = *stash;
	if ((*stash)[len] == '\0')
		*stash = NULL;
	else
	{
		*stash = ft_strdup(*stash + len);
		if (!*stash)
			return (free(temp), free(line), NULL);
	}
	return (free(temp), line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*stash;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	stash = read_line(fd, buffer, &stash);
	free(buffer);
	if (!stash || *stash == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = get_line(line, &stash);
	return (line);
}

#include <fcntl.h>
#include <stdio.h>

int	gnl(int fd)
{
	char	*s;

	s = get_next_line(fd);
	printf("%s", s);
	if (s)
	{
		free(s);
		s = NULL;
		return (1);
	}
	return (0);
}

int	main(void)
{
	int	fd1;
	int	state1;

	// int fd2;
	// int fd3;
	// int state2;
	// int state3;
	fd1 = open("file", O_RDONLY);
	// fd2 = open("file1", O_RDONLY);
	// fd3 = open("file2", O_RDONLY);
	state1 = 1;
	// state2 = 2;
	// state3 = 3;
	while (state1)
	{
		state1 = gnl(fd1);
		// state2 = gnl(fd2);
		// state3 = gnl(fd3);
		// printf("\n");
	}
	close(fd1);
	return (0);
}
