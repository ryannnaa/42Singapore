/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:35:41 by tiatan            #+#    #+#             */
/*   Updated: 2024/06/17 12:33:35 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// #include <stdio.h>

int	ft_putstr(char *str)
{
	int	result;

	result = 0;
	if (!str)
		result += ft_putstr("(null)");
	else
	{
		while (*str)
		{
			result += ft_putchar(*str);
			str++;
		}
	}
	return (result);
}

/* int	main(void)
{
	int	result = ft_putstr(NULL);
	printf("\n%d\n", result);
	return (0);
} */
