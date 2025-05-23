/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:51:44 by tiatan            #+#    #+#             */
/*   Updated: 2024/09/13 14:53:51 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n-- > 1 && *s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char str[] = "abcd";
// 	char	st[] = "abcde";
// 	size_t	i = ft_strlen(str);
// 	int	res;

// 	res = ft_strncmp(str, st, i);
// 	printf("%d\n", res);
// 	return (0);
// }
