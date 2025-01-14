/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:05:55 by tiatan            #+#    #+#             */
/*   Updated: 2024/10/27 15:08:05 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	clean_struct(t_struct *l_struct)
{
	if (l_struct->map)
		free_2d(l_struct->map);
	if (l_struct->map_ff)
		free_2d(l_struct->map_ff);
	if (l_struct->map_fd != -1)
		close(l_struct->map_fd);
}

void	clean_mlx(t_mlx *l_mlx)
{
	if (l_mlx->p_img)
		mlx_destroy_image(l_mlx->mlx_ptr, l_mlx->p_img);
	if (l_mlx->e1_img)
		mlx_destroy_image(l_mlx->mlx_ptr, l_mlx->e1_img);
	if (l_mlx->e2_img)
		mlx_destroy_image(l_mlx->mlx_ptr, l_mlx->e2_img);
	if (l_mlx->c_img)
		mlx_destroy_image(l_mlx->mlx_ptr, l_mlx->c_img);
	if (l_mlx->f_img)
		mlx_destroy_image(l_mlx->mlx_ptr, l_mlx->f_img);
	if (l_mlx->w_img)
		mlx_destroy_image(l_mlx->mlx_ptr, l_mlx->w_img);
	if (l_mlx->mlx_win)
	{
		mlx_clear_window(l_mlx->mlx_ptr, l_mlx->mlx_win);
		mlx_destroy_window(l_mlx->mlx_ptr, l_mlx->mlx_win);
	}
	if (l_mlx->mlx_ptr)
	{
		mlx_destroy_display(l_mlx->mlx_ptr);
		free(l_mlx->mlx_ptr);
	}
	clean_struct(l_mlx->map);
}

void	ft_error(char *s, t_struct *l_struct)
{
	clean_struct(l_struct);
	ft_printf("%s", s);
	exit(1);
}

int	exit_game(t_mlx *l_mlx)
{
	clean_mlx(l_mlx);
	exit(0);
}
