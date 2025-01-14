/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:20:20 by tiatan            #+#    #+#             */
/*   Updated: 2024/06/03 12:19:14 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_l;
	t_list	*new_e;
	void	*fu;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_l = NULL;
	while (lst != NULL)
	{
		fu = f(lst->content);
		new_e = ft_lstnew(fu);
		if (new_e == NULL)
		{
			ft_lstclear(&new_l, del);
			del(fu);
			return (NULL);
		}
		ft_lstadd_back(&new_l, new_e);
		lst = lst->next;
	}
	return (new_l);
}
