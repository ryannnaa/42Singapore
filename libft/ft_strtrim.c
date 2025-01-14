/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:42:01 by tiatan            #+#    #+#             */
/*   Updated: 2024/05/23 20:51:31 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

static int	check_set(char const *set, char const s1)
{
	while (*set != '\0')
	{
		if (s1 == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*dest;
	size_t		len;
	char const	*start;
	char const	*end;

	start = s1;
	while (*start != '\0' && check_set(set, *start) == 1)
	{
		start++;
	}
	end = s1 + ft_strlen(s1) - 1;
	while (end > start && check_set(set, *end) == 1)
	{
		end--;
	}
	len = end - start + 1;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, start, len);
	dest[len] = '\0';
	return (dest);
}

/*int	main(int argc, char *argv[])
{
	char	*res;

	if (argc == 3)
	{
		res = ft_strtrim(argv[1], argv[2]);
		printf("String before trim: %s\n", argv[1]);
		printf("String after trim: %s\n", res);
	}
	return (0);
}*/
