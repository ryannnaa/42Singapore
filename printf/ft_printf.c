/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:27:44 by tiatan            #+#    #+#             */
/*   Updated: 2024/06/17 17:42:03 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checkvar(const char input, va_list args)
{
	int	result;

	result = 0;
	if (input == 'c')
		result += ft_putchar(va_arg(args, int));
	else if (input == 's')
		result += ft_putstr(va_arg(args, char *));
	else if (input == 'p')
		result += ft_putptr(input, va_arg(args, unsigned long));
	else if (input == 'd' || input == 'i')
		result += ft_putnbrbase(va_arg(args, int), input, 10);
	else if (input == 'u')
		result += ft_putnbrbase(va_arg(args, unsigned int), input, 10);
	else if (input == 'x' || input == 'X')
		result += ft_putnbrbase(va_arg(args, unsigned int), input, 16);
	else if (input == '%')
		result += ft_putchar('%');
	return (result);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		result;

	result = 0;
	va_start(args, input);
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			result += ft_checkvar(*input, args);
		}
		else
		{
			write(1, input, 1);
			result++;
		}
		input++;
	}
	va_end(args);
	return (result);
}
