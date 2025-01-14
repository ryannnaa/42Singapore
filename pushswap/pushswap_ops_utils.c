/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_ops_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:17:33 by tiatan            #+#    #+#             */
/*   Updated: 2024/10/31 13:18:37 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	shift_pointer(t_stack *list_a)
{
	list_a->head->prev->next = list_a->head->next;
	list_a->head->next->prev = list_a->head->prev;
	list_a->head = list_a->head->next;
}

void	swap_node(t_stack *list)
{
	t_node	*first;
	t_node	*second;

	if (!(list->head) || list->head->next == list->head)
		return ;
	first = list->head;
	second = first->next;
	first->next = second->next;
	second->next->prev = first;
	second->prev = first->prev;
	first->prev->next = second;
	second->next = first;
	first->prev = second;
	list->head = second;
}

void	push_node(t_stack *list_a, t_stack *list_b)
{
	t_node	*to_push;

	if (list_a->head == NULL)
		return ;
	to_push = list_a->head;
	if (list_a->head->next == list_a->head)
		list_a->head = NULL;
	else
		shift_pointer(list_a);
	if (list_b->head == NULL)
	{
		list_b->head = to_push;
		to_push->next = to_push;
		to_push->prev = to_push;
	}
	else
	{
		to_push->next = list_b->head;
		to_push->prev = list_b->head->prev;
		list_b->head->prev->next = to_push;
		list_b->head->prev = to_push;
		list_b->head = to_push;
	}
}

void	rotate_list(t_stack *list)
{
	list->head = list->head->next;
}

void	rrotate_list(t_stack *list)
{
	list->head = list->head->prev;
}
