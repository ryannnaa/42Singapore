/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_append.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 22:55:26 by tiatan            #+#    #+#             */
/*   Updated: 2024/10/15 20:24:30 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_append(const char *s, size_t len, char c)
{
	char			*dest;
	unsigned int	i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (len + 2));
	if (dest == NULL)
		return (NULL);
	while (*(s + i) != '\0' && *(s + i) != c)
	{
		dest[i] = s[i];
		i++;
	}
	dest[len] = '/';
	dest[len + 1] = '\0';
	return (dest);
}
