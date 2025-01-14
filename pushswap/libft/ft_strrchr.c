/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:32:24 by tiatan            #+#    #+#             */
/*   Updated: 2024/05/28 23:27:39 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;

	temp = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			temp = (char *)s;
		s++;
	}
	if (*s == (char)c)
	{
		temp = (char *)s;
	}
	return (temp);
}
