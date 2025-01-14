/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:12:51 by tiatan            #+#    #+#             */
/*   Updated: 2024/10/31 14:09:31 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	int				size;
}					t_stack;

void				rrotate_list(t_stack *list);
void				rrotate(t_stack *list, char *message);
void				rotate_list(t_stack *list);
void				rotate(t_stack *list, char *message);
void				push_node(t_stack *list_a, t_stack *list_b);
void				push(t_stack *list1, t_stack *list2, char *message);
void				swap_node(t_stack *list);
void				swap(t_stack *list, char *message);
void				sort_list(t_stack *list_a, t_stack *list_b);
void				index_stack(t_stack *list_a);
void				ft_error(char *s, t_stack *l);
void				free_list(t_stack *l);
void				free_2d(char **memory);
void				init_list(t_stack *l);
void				insert_node(t_stack *l, int data);
long				ft_atol(const char *nptr);
int					base2(int number, int sf);
int					count_bits(t_stack *list);
int					check_sorted(t_stack *list);
int					push_swap(int argc, char **argv);

#endif