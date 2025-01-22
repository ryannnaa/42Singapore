/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:50:08 by tiatan            #+#    #+#             */
/*   Updated: 2024/05/29 15:27:59 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <bsd/string.h>
//#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	i = 0;
	if (size <= d_len)
		return (size + s_len);
	while (src[i] != '\0' && d_len + i < size - 1)
	{
		dst[d_len + i] = src[i];
		i++;
	}
	if (d_len + i < size)
		dst[d_len + i] = '\0';
	return (d_len + s_len);
}

/*int main() {
    char dst1[20] = "Hello, ";
    char dst2[20] = "Hello, ";
    const char *src = "World!1234";
    size_t size = 15;
    
    // Using standard strlcat
    size_t result1 = strlcat(dst1, src, size);
    
    // Using custom ft_strlcat
    size_t result2 = ft_strlcat(dst2, src, size);

    // Print results
    printf("Standard strlcat:\n");
    printf("Result: %zu\n", result1);
    printf("dst: %s\n\n", dst1);

    printf("Custom ft_strlcat:\n");
    printf("Result: %zu\n", result2);
    printf("dst: %s\n", dst2);

    return 0;
}*/
