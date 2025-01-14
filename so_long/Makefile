# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 15:53:38 by tiatan            #+#    #+#              #
#    Updated: 2024/10/26 18:42:22 by tiatan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC				= cc
CFLAGS			= -Wall -Werror -Wextra -g
MLXFLAGS		= -lmlx -lX11 -lXext

# Directories
LIBFT_DIR		= libft
LIBPRINTF_DIR	= libprintf
MLX_DIR			= minilibx-linux

# Static Libraries
LIBFT_A			= $(LIBFT_DIR)/libft.a
LIBPRINTF_A		= $(LIBPRINTF_DIR)/libprintf.a
MLX_A			= $(MLX_DIR)/libmlx_Linux.a

# Main Program
SRCS			= so_long.c map_check.c error_handle.c path_check.c draw_map.c game_start.c
OBJS			= $(SRCS:.c=.o)
INCLUDES		= -I./header/ -I$(MLX_DIR)
NAME			= so_long

# Default Rule
all:			$(NAME)

# Ensure libraries are built
$(LIBFT_A):
				$(MAKE) -C $(LIBFT_DIR)
	
$(LIBPRINTF_A):
				$(MAKE) -C $(LIBPRINTF_DIR)

$(MLX_A):
				$(MAKE) -C $(MLX_DIR)

# Rule to build the executable
$(NAME):		$(OBJS) $(LIBFT_A) $(LIBPRINTF_A) $(MLX_A)
				$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -L$(LIBPRINTF_DIR) -L$(MLX_DIR) -lft -lprintf $(MLXFLAGS)

# Pattern rule to compile main program
%.o:			%.c 
				$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

# Other Rules
clean:
				@/bin/rm -f $(OBJS)
				$(MAKE) -C $(LIBFT_DIR) clean
				$(MAKE) -C $(LIBPRINTF_DIR) clean
				$(MAKE) -C $(MLX_DIR) clean

fclean:			clean
				@/bin/rm -f $(NAME)
				$(MAKE) -C $(LIBFT_DIR) fclean
				$(MAKE) -C $(LIBPRINTF_DIR) fclean
				$(MAKE) -C $(MLX_DIR) clean

re:				fclean all

.PHONY:			all clean fclean re
