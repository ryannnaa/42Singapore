/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:38:03 by tiatan            #+#    #+#             */
/*   Updated: 2024/10/26 22:15:45 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_window(t_mlx *l_mlx, t_struct *l_struct)
{
	l_mlx->mlx_ptr = mlx_init();
	if (!l_mlx->mlx_ptr)
	{
		clean_mlx(l_mlx);
		ft_error("Error: Unable to intialise MLX pointer\n", l_struct);
	}
	l_mlx->mlx_win = mlx_new_window(l_mlx->mlx_ptr, l_struct->map_w * 64,
			l_struct->map_h * 64, "so_long");
	if (!l_mlx->mlx_win)
	{
		clean_mlx(l_mlx);
		ft_error("Error: Unable to create MLX window\n", l_struct);
	}
}

void	process_xpm(t_mlx *l_mlx, t_struct *l_struct)
{
	int	w;
	int	h;

	l_mlx->p_img = mlx_xpm_file_to_image(l_mlx->mlx_ptr, "./images/p.xpm", &w,
			&h);
	l_mlx->e1_img = mlx_xpm_file_to_image(l_mlx->mlx_ptr, "./images/e_c.xpm",
			&w, &h);
	l_mlx->e2_img = mlx_xpm_file_to_image(l_mlx->mlx_ptr, "./images/e_o.xpm", &w,
			&h);
	l_mlx->c_img = mlx_xpm_file_to_image(l_mlx->mlx_ptr, "./images/c.xpm", &w,
			&h);
	l_mlx->f_img = mlx_xpm_file_to_image(l_mlx->mlx_ptr, "./images/f.xpm", &w,
			&h);
	l_mlx->w_img = mlx_xpm_file_to_image(l_mlx->mlx_ptr, "./images/w.xpm", &w,
			&h);
	if (!l_mlx->p_img || !l_mlx->e1_img || !l_mlx->e2_img || !l_mlx->c_img
		|| !l_mlx->f_img || !l_mlx->w_img)
	{
		clean_mlx(l_mlx);
		ft_error("Error: Unable to process images\n", l_struct);
	}
}

int	put_image(t_mlx *l_mlx, t_struct *l_struct)
{
	if (l_struct->map[l_struct->i][l_struct->j] == 'P')
		return (mlx_put_image_to_window(l_mlx->mlx_ptr, l_mlx->mlx_win,
				l_mlx->p_img, l_struct->j * 64, l_struct->i * 64));
	if (l_struct->map[l_struct->i][l_struct->j] == 'E')
		return (mlx_put_image_to_window(l_mlx->mlx_ptr, l_mlx->mlx_win,
				l_mlx->e1_img, l_struct->j * 64, l_struct->i * 64));
	if (l_struct->map[l_struct->i][l_struct->j] == 'C')
		return (mlx_put_image_to_window(l_mlx->mlx_ptr, l_mlx->mlx_win,
				l_mlx->c_img, l_struct->j * 64, l_struct->i * 64));
	if (l_struct->map[l_struct->i][l_struct->j] == '0')
		return (mlx_put_image_to_window(l_mlx->mlx_ptr, l_mlx->mlx_win,
				l_mlx->f_img, l_struct->j * 64, l_struct->i * 64));
	if (l_struct->map[l_struct->i][l_struct->j] == '1')
		return (mlx_put_image_to_window(l_mlx->mlx_ptr, l_mlx->mlx_win,
				l_mlx->w_img, l_struct->j * 64, l_struct->i * 64));
	return (0);
}

void	put_images(t_mlx *l_mlx, t_struct *l_struct)
{
	l_struct->i = 0;
	process_xpm(l_mlx, l_struct);
	while (l_struct->map[l_struct->i])
	{
		l_struct->j = 0;
		while (l_struct->map[l_struct->i][l_struct->j])
		{
			if (!put_image(l_mlx, l_struct))
			{
				clean_mlx(l_mlx);
				ft_error("Error: Unable to put image to window\n", l_struct);
			}
			l_struct->j++;
		}
		l_struct->i++;
	}
}

void	draw_map(t_mlx *l_mlx, t_struct *l_struct)
{
	create_window(l_mlx, l_struct);
	put_images(l_mlx, l_struct);
}
