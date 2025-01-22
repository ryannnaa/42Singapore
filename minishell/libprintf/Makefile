# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 16:42:32 by tiatan            #+#    #+#              #
#    Updated: 2024/09/03 16:56:18 by tiatan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC				= cc
CFLAGS			= -Wall -Werror -Wextra

# Main Program
SRCS			= ft_printf.c ft_putchar.c ft_putnbrbase.c ft_putptr.c ft_putstr.c
OBJS			= $(SRCS:.c=.o)
INCLUDES		= ft_printf.h
NAME			= libprintf.a

# Default Rule
all :			$(NAME)

# Rule to build static library
$(NAME)	:		$(OBJS)
				@ar rcs $(NAME) $(OBJS)

# Pattern rule to compile the static library
%.o:			%.c $(INCLUDES)
				$(CC) $(CFLAGS) -c $< -o $@

# Other Rules
clean	:	
				@/bin/rm -f $(OBJS)

fclean	: 		clean
				@/bin/rm -f $(NAME)

re: 			fclean all

.PHONY	: 		all clean fclean re
