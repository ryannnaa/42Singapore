/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:12:29 by tiatan            #+#    #+#             */
/*   Updated: 2024/06/17 17:45:24 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr16(unsigned long n, const char input, unsigned int base)
{
	char	*array;
	int		result;

	result = 0;
	array = "0123456789abcdef";
	if (n >= base)
		result += ft_putnbrbase(n / base, input, base);
	result += ft_putchar(array[n % base]);
	return (result);
}

int	ft_putptr(const char input, unsigned long n)
{
	int	result;

	result = 0;
	if (n == 0)
		result += ft_putstr("(nil)");
	else
	{
		result += ft_putstr("0x");
		result += ft_putnbr16(n, input, 16);
	}
	return (result);
}
