# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 15:53:38 by tiatan            #+#    #+#              #
#    Updated: 2025/01/14 15:45:09 by tiatan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC				= cc
CFLAGS			= -Wall -Werror -Wextra -g -pthread

# Additional flags to optimise: -o3 -fsanitize=thread

# Directories
#LIBFT_DIR		= libft
#LIBPRINTF_DIR	= libprintf

# Static Libraries
#LIBFT_A			= $(LIBFT_DIR)/libft.a
#LIBPRINTF_A		= $(LIBPRINTF_DIR)/libprintf.a

# Main Program
SRCS			= error_handle.c main.c utils.c threads.c mutex.c routine_1.c routine_2.c
OBJS			= $(SRCS:.c=.o)
#INCLUDES		= -I philo.h
NAME			= philo

# Default Rule
all:			$(NAME)

# Ensure libraries are built
#$(LIBFT_A):
#				$(MAKE) -C $(LIBFT_DIR)
	
#$(LIBPRINTF_A):
#				$(MAKE) -C $(LIBPRINTF_DIR)

# Rule to build the executable
$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) -o $@ $^

# Pattern rule to compile main program
%.o:			%.c 
				$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

# Other Rules
clean:
				@/bin/rm -f $(OBJS)
#				$(MAKE) -C $(LIBFT_DIR) clean
#				$(MAKE) -C $(LIBPRINTF_DIR) clean

fclean:			clean
				@/bin/rm -f $(NAME)
#				$(MAKE) -C $(LIBFT_DIR) fclean
#				$(MAKE) -C $(LIBPRINTF_DIR) fclean

re:				fclean all

.PHONY:			all clean fclean re
