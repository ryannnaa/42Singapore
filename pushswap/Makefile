# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 15:53:38 by tiatan            #+#    #+#              #
#    Updated: 2024/10/30 15:44:19 by tiatan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC				= cc
CFLAGS			= -Wall -Werror -Wextra -g

# Directories
LIBFT_DIR		= libft
LIBPRINTF_DIR	= libprintf

# Static Libraries
LIBFT_A			= $(LIBFT_DIR)/libft.a
LIBPRINTF_A		= $(LIBPRINTF_DIR)/libprintf.a

# Main Program
SRCS			= pushswap.c pushswap_list.c error_handle.c ft_atol.c pushswap_sort.c pushswap_sort_utils.c pushswap_ops.c pushswap_ops_utils.c
OBJS			= $(SRCS:.c=.o)
INCLUDES		= -I./header/
NAME			= push_swap

# Default Rule
all:			$(NAME)

# Ensure libraries are built
$(LIBFT_A):
				$(MAKE) -C $(LIBFT_DIR)
	
$(LIBPRINTF_A):
				$(MAKE) -C $(LIBPRINTF_DIR)

# Rule to build the executable
$(NAME):		$(OBJS) $(LIBFT_A) $(LIBPRINTF_A)
				$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -L$(LIBPRINTF_DIR) -lft -lprintf

# Pattern rule to compile main program
%.o:			%.c 
				$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

# Other Rules
clean:
				@/bin/rm -f $(OBJS)
				$(MAKE) -C $(LIBFT_DIR) clean
				$(MAKE) -C $(LIBPRINTF_DIR) clean

fclean:			clean
				@/bin/rm -f $(NAME)
				$(MAKE) -C $(LIBFT_DIR) fclean
				$(MAKE) -C $(LIBPRINTF_DIR) fclean

re:				fclean all

.PHONY:			all clean fclean re
