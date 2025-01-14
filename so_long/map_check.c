/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:35:18 by tiatan            #+#    #+#             */
/*   Updated: 2024/10/27 16:41:58 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_struct *l_struct)
{
	char	temp[1200];
	int		bytes_read;

	{
		bytes_read = read(l_struct->map_fd, temp, 1200);
		temp[bytes_read] = '\0';
		if (bytes_read == -1)
			ft_error("Error: Unable to read from .ber file\n", l_struct);
		else if (bytes_read == 0)
			ft_error("Error: Empty .ber file\n", l_struct);
		else if (bytes_read > 1000)
			ft_error("Error: Map is too big, please use a smaller map\n",
				l_struct);
		l_struct->map = ft_split(temp, '\n');
		l_struct->map_ff = ft_split(temp, '\n');
		if (!l_struct->map || !l_struct->map_ff)
			ft_error("Error splitting the map\n", l_struct);
	}
}

void	get_width(t_struct *l_struct)
{
	while (l_struct->map[l_struct->map_h][l_struct->map_w])
	{
		if (l_struct->map[l_struct->map_h][l_struct->map_w] != '1')
			ft_error("Error: Map is not surrounded by walls\n", l_struct);
		l_struct->map_w++;
	}
}

void	check_last(char *s, t_struct *l_struct)
{
	int	i;

	i = 0;
	while (i < l_struct->map_w - 1)
	{
		if (s[i] != '1')
			ft_error("Error: Map is not surrounded by walls\n", l_struct);
		i++;
	}
}

int	check_c(int c, t_struct *l_struct)
{
	if (c == '0' || c == '1')
		return (2);
	else if (c == 'C')
	{
		l_struct->num_c++;
		return (2);
	}
	else if (c == 'E')
	{
		l_struct->num_e++;
		l_struct->e_x = l_struct->i;
		l_struct->e_y = l_struct->map_h;
		return (2);
	}
	else if (c == 'P')
	{
		l_struct->num_p++;
		l_struct->player->p_x = l_struct->i;
		l_struct->player->p_y = l_struct->map_h;
		return (1);
	}
	else
		return (0);
}

void	check_grid(t_struct *l_struct)
{
	get_width(l_struct);
	while (l_struct->map[l_struct->map_h])
	{
		l_struct->i = 0;
		while (l_struct->i < l_struct->map_w)
		{
			if (l_struct->map[l_struct->map_h][0] != '1')
				ft_error("Error: Map is not surrounded by walls\n", l_struct);
			if (check_c(l_struct->map[l_struct->map_h][l_struct->i],
				l_struct) == 0)
				ft_error("Error: Invalid character in map\n", l_struct);
			l_struct->i++;
		}
		if (l_struct->map[l_struct->map_h][l_struct->map_w - 1] != '1')
			ft_error("Error: Map is not surrounded by walls\n", l_struct);
		if (l_struct->i != l_struct->map_w
			|| l_struct->map[l_struct->map_h][l_struct->i] != '\0')
			ft_error("Error: Map is not a rectangle\n", l_struct);
		l_struct->map_h++;
	}
	check_last(l_struct->map[l_struct->map_h - 1], l_struct);
	if (l_struct->num_c < 1 || l_struct->num_p != 1 || l_struct->num_e != 1)
		ft_error("Error: Include only 1 E, 1 P at least 1 C in map\n",
			l_struct);
}
