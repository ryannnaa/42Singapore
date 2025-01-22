/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:57:14 by tiatan            #+#    #+#             */
/*   Updated: 2024/05/28 16:53:01 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static size_t	int_len(int n)
{
	size_t	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	char			*res;
	size_t			len;

	len = int_len(n);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (res == NULL)
		return (NULL);
	if (n < 0)
	{
		nbr = -n;
		res[0] = '-';
	}
	else
		nbr = n;
	res[len] = '\0';
	if (nbr == 0)
		*res = '0';
	while (len-- > 0 && nbr != 0)
	{
		res[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (res);
}

/*int	main(int argc, char *argv[])
{
	int		temp;
	char	*res;

	if (argc == 2)
	{
		temp = atoi(argv[1]);
		res = ft_itoa(temp);
		printf("%s", res);
	}
	return (0);
}*/
