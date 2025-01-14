/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:01:24 by tiatan            #+#    #+#             */
/*   Updated: 2024/06/03 12:10:09 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*int	main(int argc, char *argv[])
{
	size_t	res1;
	size_t	res2;

	if (argc == 2)
	{
		res1 = ft_strlen(argv[1]);
		res2 = strlen(argv[1]);
		printf("%lu", res1);
		printf("%lu", res2);
	}
	return 0;
}*/
