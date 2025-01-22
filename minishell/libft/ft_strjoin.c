/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:34:46 by tiatan            #+#    #+#             */
/*   Updated: 2024/05/21 17:14:32 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dest = (char *)malloc((sizeof(char)) * (len1 + len2 + 1));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s1, len1);
	ft_memcpy(dest + len1, s2, len2);
	dest[len1 + len2] = '\0';
	return (dest);
}
