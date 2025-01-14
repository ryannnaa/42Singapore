/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_sort_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:24:45 by tiatan            #+#    #+#             */
/*   Updated: 2024/10/31 12:41:44 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	count_index(t_node *current_node, t_node *next_node)
{
	int	i;

	i = 0;
	while (next_node != current_node)
	{
		if (current_node->data > next_node->data)
			i++;
		next_node = next_node->next;
	}
	return (i);
}

int	check_sorted(t_stack *list)
{
	t_node	*current_node;
	t_node	*next_node;
	int		i;

	i = 1;
	current_node = list->head;
	while (i < list->size)
	{
		next_node = current_node->next;
		if (current_node->data > next_node->data)
			return (0);
		i++;
		current_node = current_node->next;
	}
	return (1);
}

void	index_stack(t_stack *list_a)
{
	t_node	*current_node;
	t_node	*next_node;

	current_node = list_a->head;
	while (current_node->next != list_a->head)
	{
		next_node = current_node->next;
		current_node->index = count_index(current_node, next_node);
		current_node = current_node->next;
	}
	if (current_node->next == list_a->head)
	{
		next_node = current_node->next;
		current_node->index = count_index(current_node, next_node);
	}
}

int	count_bits(t_stack *list)
{
	int	i;
	int	j;

	i = list->size - 1;
	j = 0;
	while (i > 0)
	{
		i >>= 1;
		j++;
	}
	return (j);
}

int	base2(int number, int sf)
{
	return ((number >> sf) & 1);
}
