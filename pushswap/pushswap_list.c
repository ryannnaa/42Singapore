/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_list_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:13:51 by tiatan            #+#    #+#             */
/*   Updated: 2024/10/27 21:04:05 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	init_list(t_stack *l)
{
	l->head = NULL;
	l->size = 0;
}

t_node	*create_node(int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->index = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	insert_node(t_stack *l, int data)
{
	t_node	*new_node;
	t_node	*last;

	last = NULL;
	new_node = create_node(data);
	if (!new_node)
		return ;
	if (l->head == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		l->head = new_node;
	}
	else
	{
		last = l->head->prev;
		new_node->next = l->head;
		new_node->prev = last;
		last->next = new_node;
		l->head->prev = new_node;
	}
}
