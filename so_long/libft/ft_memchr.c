/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:38:20 by tiatan            #+#    #+#             */
/*   Updated: 2024/06/04 17:47:23 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*p;
	unsigned char		cc;

	p = (unsigned const char *)s;
	cc = (unsigned char)c;
	while (n-- > 0)
	{
		if (*p == cc)
			return ((void *)p);
		p++;
	}
	return (NULL);
}
