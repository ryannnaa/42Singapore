/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:37:28 by tiatan            #+#    #+#             */
/*   Updated: 2024/10/30 22:15:45 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(t_stack *list, char *message)
{
	swap_node(list);
	ft_printf("%s\n", message);
}

void	push(t_stack *list1, t_stack *list2, char *message)
{
	push_node(list1, list2);
	ft_printf("%s\n", message);
}

void	rotate(t_stack *list, char *message)
{
	rotate_list(list);
	ft_printf("%s\n", message);
}

void	rrotate(t_stack *list, char *message)
{
	rrotate_list(list);
	ft_printf("%s\n", message);
}
