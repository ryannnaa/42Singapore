/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:47:21 by tiatan            #+#    #+#             */
/*   Updated: 2024/10/31 14:07:21 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_3(t_stack *list_a)
{
	if (list_a->head->index > list_a->head->next->index
		&& list_a->head->index > list_a->head->prev->index)
	{
		rotate(list_a, "ra");
	}
	if (list_a->head->next->index > list_a->head->index
		&& list_a->head->next->index > list_a->head->prev->index)
	{
		rrotate(list_a, "rra");
	}
	if (list_a->head->index > list_a->head->next->index)
	{
		swap(list_a, "sa");
	}
}

void	sort_4(t_stack *list_a, t_stack *list_b, int i)
{
	while (1)
	{
		if (list_a->head->index == i)
		{
			push(list_a, list_b, "pb");
			break ;
		}
		else if (list_a->head->prev->index == i)
			rrotate(list_a, "rra");
		else
			rotate(list_a, "ra");
	}
	sort_3(list_a);
	push(list_b, list_a, "pa");
}

void	sort_5(t_stack *list_a, t_stack *list_b)
{
	while (1)
	{
		if (list_a->head->index == 0)
		{
			push(list_a, list_b, "pb");
			break ;
		}
		else if (list_a->head->prev->index == 0)
			rrotate(list_a, "rra");
		else
			rotate(list_a, "ra");
	}
	sort_4(list_a, list_b, 1);
	push(list_b, list_a, "pa");
	if (list_a->head->index > list_a->head->next->index)
		swap(list_a, "sa");
}

void	radix_sort(t_stack *list_a, t_stack *list_b)
{
	int	max_bit;
	int	i;
	int	size;

	max_bit = count_bits(list_a);
	i = 0;
	while (max_bit > i)
	{
		size = list_a->size;
		while (size > 0)
		{
			if (base2(list_a->head->index, i) == 0)
				push(list_a, list_b, "pb");
			else
				rotate(list_a, "ra");
			size--;
		}
		while (list_b->head)
			push(list_b, list_a, "pa");
		i++;
	}
}

void	sort_list(t_stack *list_a, t_stack *list_b)
{
	if (list_a->size == 5)
		sort_5(list_a, list_b);
	else if (list_a->size == 4)
		sort_4(list_a, list_b, 0);
	else if (list_a->size == 3)
		sort_3(list_a);
	else
		radix_sort(list_a, list_b);
}
