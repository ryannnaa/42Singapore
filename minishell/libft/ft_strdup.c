/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 22:55:26 by tiatan            #+#    #+#             */
/*   Updated: 2024/05/28 23:23:41 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*dest;
	size_t			len;
	unsigned int	i;

	i = 0;
	len = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (*(s + i) != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[len] = '\0';
	return (dest);
}
