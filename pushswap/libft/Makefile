# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 16:42:32 by tiatan            #+#    #+#              #
#    Updated: 2024/10/27 17:51:05 by tiatan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC				= cc
CFLAGS			= -Wall -Werror -Wextra

# Main Program
SRCS			= ft_isascii.c ft_memcpy.c ft_putstr_fd.c ft_strlcat.c ft_strrchr.c \
				ft_atoi.c ft_isdigit.c ft_memmove.c ft_split.c ft_strlcpy.c ft_strtrim.c \
				ft_bzero.c ft_isprint.c ft_memset.c ft_strchr.c ft_strlen.c ft_substr.c \
				ft_calloc.c ft_itoa.c ft_putchar_fd.c ft_strdup.c ft_strmapi.c ft_tolower.c \
				ft_isalnum.c ft_memchr.c ft_putendl_fd.c ft_striteri.c ft_strncmp.c ft_toupper.c \
				ft_isalpha.c ft_memcmp.c ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c get_next_line.c
OBJS			= $(SRCS:.c=.o)
INCLUDES		= libft.h
NAME			= libft.a

# Bonus Program
BONUS_SRCS		= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
				ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUS_OBJS		= $(BONUS_SRCS:.c=.o)

# Default Rule
all :		$(NAME)

# Rule to build static library
$(NAME)	:		$(OBJS)
				@ar rcs $(NAME) $(OBJS)

# Pattern rule to compile the static library
%.o:			%.c $(INCLUDES)
				$(CC) $(CFLAGS) -c $< -o $@

# Bonus Rule
bonus	:		$(OBJS) $(BONUS_OBJS)
				@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

# Other Rules
clean	:	
				/bin/rm -f $(OBJS) $(BONUS_OBJS)

fclean	: 		clean
				/bin/rm -f $(NAME)

re: 			fclean all

.PHONY	: 		all bonus clean fclean re
