/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:55:54 by tiatan            #+#    #+#             */
/*   Updated: 2024/10/22 12:53:23 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid(char **arr, int x, int y, t_struct *l_struct)
{
	if (y > l_struct->map_h - 1 || y < 0 || x > l_struct->map_w - 1 || x < 0)
		return (0);
	if (arr[y][x] == '1')
		return (0);
	return (1);
}

void	flood_fill(int x, int y, char c, t_struct *l_struct)
{
	if (!is_valid(l_struct->map_ff, x, y, l_struct))
		return ;
	if (l_struct->map_ff[y][x] == 'C')
		l_struct->i++;
	if (l_struct->map_ff[y][x] == 'E')
		l_struct->j++;
	l_struct->map_ff[y][x] = c;
	flood_fill(x + 1, y, c, l_struct);
	flood_fill(x - 1, y, c, l_struct);
	flood_fill(x, y + 1, c, l_struct);
	flood_fill(x, y - 1, c, l_struct);
}

void	check_path(t_struct *l_struct)
{
	l_struct->i = 0;
	l_struct->j = 0;
	flood_fill(l_struct->player->p_x, l_struct->player->p_y, '1', l_struct);
	if (l_struct->i != l_struct->num_c)
		ft_error("Error: Ensure that all Collectibles can be reached\n",
			l_struct);
	if (l_struct->j != l_struct->num_e)
		ft_error("Error: Ensure that the Exit can be reached\n", l_struct);
}
