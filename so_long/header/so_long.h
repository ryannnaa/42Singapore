/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:49:23 by tiatan            #+#    #+#             */
/*   Updated: 2024/10/27 15:31:27 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_W 119
# define KEY_ESC 65307

# include "ft_printf.h"
# include "libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

enum
{
	keydown = 2,
	keyup = 3,
	mousedown = 4,
	mouseup = 5,
	mousemove = 6,
	expose = 12,
	destroy = 17
};

typedef struct s_player
{
	int			p_x;
	int			p_y;
}				t_player;

typedef struct s_struct
{
	int			argc;
	int			map_fd;
	int			map_w;
	int			map_h;
	int			num_c;
	int			num_p;
	int			num_e;
	int			i;
	int			j;
	int			e_x;
	int			e_y;
	char		**argv;
	char		**map;
	char		**map_ff;
	t_player	*player;
}				t_struct;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*mlx_win;
	void		*p_img;
	void		*e1_img;
	void		*e2_img;
	void		*c_img;
	void		*w_img;
	void		*f_img;
	int			move;
	int			steps;
	t_struct	*map;
}				t_mlx;

int    			exit_game(t_mlx *l_mlx);
void			game_start(t_mlx *l_mlx, t_struct *l_struct);
void			draw_map(t_mlx *l_mlx, t_struct *l_struct);
void			clean_mlx(t_mlx *l_mlx);
void			clean_struct(t_struct *l_struct);
void			ft_error(char *s, t_struct *l_struct);
void			check_path(t_struct *l_struct);
void			check_grid(t_struct *l_struct);
void			read_map(t_struct *l_struct);
int				main(int argc, char **argv);

#endif