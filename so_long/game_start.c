/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:00:55 by tiatan            #+#    #+#             */
/*   Updated: 2024/10/28 15:44:29 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int key, t_mlx *l_mlx)
{
	if (l_mlx->move == 0)
	{
		if (key == KEY_UP || key == KEY_W)
			l_mlx->move = 1;
		if (key == KEY_DOWN || key == KEY_S)
			l_mlx->move = 2;
		if (key == KEY_LEFT || key == KEY_A)
			l_mlx->move = 3;
		if (key == KEY_RIGHT || key == KEY_D)
			l_mlx->move = 4;
	}
	if (key == KEY_ESC)
		exit_game(l_mlx);
	return (0);
}

void	update_window(t_mlx *l_mlx, int x, int y)
{
	if (l_mlx->map->map[y][x] == 'E' && l_mlx->map->num_c == 0)
	{
		ft_printf("\nGame completed, move on\n");
		exit_game(l_mlx);
	}
	if (l_mlx->map->map[y][x] == 'C')
		l_mlx->map->num_c--;
	if (l_mlx->map->num_c == 0)
		mlx_put_image_to_window(l_mlx->mlx_ptr, l_mlx->mlx_win, l_mlx->e2_img,
			l_mlx->map->e_x * 64, l_mlx->map->e_y * 64);
	mlx_put_image_to_window(l_mlx->mlx_ptr, l_mlx->mlx_win, l_mlx->f_img,
		l_mlx->map->player->p_x * 64, l_mlx->map->player->p_y * 64);
	l_mlx->map->map[l_mlx->map->player->p_y][l_mlx->map->player->p_x] = '0';
	mlx_put_image_to_window(l_mlx->mlx_ptr, l_mlx->mlx_win, l_mlx->p_img, x
		* 64, y * 64);
	if (l_mlx->map->player->p_x == l_mlx->map->e_x
		&& l_mlx->map->player->p_y == l_mlx->map->e_y)
	{
		mlx_put_image_to_window(l_mlx->mlx_ptr, l_mlx->mlx_win, l_mlx->e1_img,
			l_mlx->map->player->p_x * 64, l_mlx->map->player->p_y * 64);
		l_mlx->map->map[l_mlx->map->player->p_y][l_mlx->map->player->p_x] = 'E';
	}
	l_mlx->map->player->p_x = x;
	l_mlx->map->player->p_y = y;
}

int	run_game(t_mlx *l_mlx)
{
	int	new_x;
	int	new_y;

	new_x = l_mlx->map->player->p_x;
	new_y = l_mlx->map->player->p_y;
	if (l_mlx->move > 0)
	{
		if (l_mlx->move == 1)
			new_y -= 1;
		if (l_mlx->move == 2)
			new_y += 1;
		if (l_mlx->move == 3)
			new_x -= 1;
		if (l_mlx->move == 4)
			new_x += 1;
		if (l_mlx->map->map[new_y][new_x] != '1')
		{
			write(1, "\r", 2);
			ft_printf("Steps taken: %d", ++l_mlx->steps);
			update_window(l_mlx, new_x, new_y);
		}
		l_mlx->move = 0;
	}
	return (0);
}

void	game_start(t_mlx *l_mlx, t_struct *l_struct)
{
	draw_map(l_mlx, l_struct);
	mlx_hook(l_mlx->mlx_win, keydown, 1L << 0, key_press, l_mlx);
	mlx_hook(l_mlx->mlx_win, destroy, 1L << 0, exit_game, l_mlx);
	mlx_loop_hook(l_mlx->mlx_ptr, run_game, l_mlx);
	mlx_loop(l_mlx->mlx_ptr);
	mlx_loop_end(l_mlx->mlx_ptr);
}
