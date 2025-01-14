/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:19:16 by tiatan            #+#    #+#             */
/*   Updated: 2024/07/24 16:35:41 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//#include <stdio.h>

int	ft_putnbrbase(long n, const char input, unsigned int base)
{
	char				*array;
	unsigned long		nb;
	int					result;

	result = 0;
	if (base < 2 || base > 16)
		return (0);
	if (input == 'X')
		array = "0123456789ABCDEF";
	else
		array = "0123456789abcdef";
	if (n < 0)
	{
		result += ft_putchar('-');
		nb = -n;
	}
	else
		nb = n;
	if (nb >= base)
		result += ft_putnbrbase(nb / base, input, base);
	result += ft_putchar(array[nb % base]);
	return (result);
}

/* int	main(void)
{
	int	result1 = ft_putnbrbase(-12345, 'd', 10);
	write (1, "\n", 1);
	int	result2 = ft_putnbrbase(-12345, 'i', 16);
	printf("\nResult1 = %d\n", result1);
	printf("\nResult1 = %d\n", result2);
	return (0);
} */
