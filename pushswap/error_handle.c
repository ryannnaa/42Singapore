/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:04:23 by tiatan            #+#    #+#             */
/*   Updated: 2024/11/01 18:21:09 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_2d(char **memory)
{
	size_t	i;

	i = 0;
	while (memory[i])
	{
		free(memory[i]);
		i++;
	}
	free(memory);
	memory = NULL;
}

void	free_list(t_stack *l)
{
	t_node	*temp;
	t_node	*next_node;

	if (l == NULL || l->head == NULL)
		return ;
	temp = l->head;
	while (temp)
	{
		next_node = temp->next;
		free(temp);
		temp = next_node;
		if (temp == l->head)
			break ;
	}
	l->head = NULL;
}

void	ft_error(char *s, t_stack *l)
{
	free_list(l);
	ft_putstr_fd(s, 2);
	exit(1);
}
