# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 16:42:32 by tiatan            #+#    #+#              #
#    Updated: 2024/06/17 17:45:57 by tiatan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc

CFLAGS		= -Wall -Werror -Wextra

NAME		= libftprintf.a

SRCS		= ft_printf.c ft_putchar.c ft_putnbrbase.c ft_putptr.c ft_putstr.c

OBJ		= $(SRCS:.c=.o)

INCLUDES	= ft_printf.h

all :		$(NAME)

$(NAME)	:	$(OBJ)
		@ar rcs $(NAME) $(OBJ)

%.o:		%.c $(INCLUDES)
		$(CC) $(CFLAGS) -c $< -o $@

clean	:	
		@/bin/rm -f $(OBJ)

fclean	: 	clean
		@/bin/rm -f $(NAME)

re: 		fclean all

.PHONY	: 	all clean fclean re
