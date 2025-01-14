/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:52:13 by tiatan            #+#    #+#             */
/*   Updated: 2024/10/27 00:59:15 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(int argc, char **argv, t_struct *l_struct, t_player *p)
{
	l_struct->argc = argc;
	l_struct->map_fd = -1;
	l_struct->map_w = 0;
	l_struct->map_h = 0;
	l_struct->num_c = 0;
	l_struct->num_p = 0;
	l_struct->num_e = 0;
	l_struct->i = 0;
	l_struct->j = 0;
	l_struct->e_x = 0;
	l_struct->e_y = 0;
	l_struct->argv = argv;
	l_struct->map = NULL;
	l_struct->map_ff = NULL;
	l_struct->player = p;
}

void    init_mlx(t_mlx *l_mlx, t_struct *l_struct)
{
    l_mlx->mlx_ptr = NULL;
    l_mlx->mlx_win = NULL;
	l_mlx->p_img = NULL;
	l_mlx->e1_img = NULL;
	l_mlx->e2_img = NULL;
	l_mlx->c_img = NULL;
	l_mlx->w_img = NULL;
	l_mlx->f_img = NULL;
	l_mlx->move = 0;
	l_mlx->steps = 0;
	l_mlx->map = l_struct;
}

void	check_file(t_struct *l_struct)
{
	size_t	i;

	i = 0;
	while (l_struct->argv[1][i] != '.' && l_struct->argv[1][i] != '\0')
	{
		i++;
	}
	if (strncmp(&l_struct->argv[1][i], ".ber", 4) != 0)
	{
		ft_error("Error: File extension, please use a .ber file\n", l_struct);
	}
	else
	{
		l_struct->map_fd = open(l_struct->argv[1], O_RDONLY);
		if (l_struct->map_fd == -1)
		{
			ft_error("Error: Unable to open .ber file\n", l_struct);
		}
	}
}

int	main(int argc, char **argv)
{
	t_struct	l_struct;
    t_mlx       l_mlx;
	t_player	player;

	if (argc != 2)
		ft_printf("Error: Invalid number of arguments\n");
	else
	{
		init_struct(argc, argv, &l_struct, &player);
		check_file(&l_struct);
		read_map(&l_struct);
		check_grid(&l_struct);
		check_path(&l_struct);
        init_mlx(&l_mlx, &l_struct);
        game_start(&l_mlx, &l_struct);
    	clean_mlx(&l_mlx);
		return (0);
	}
}
