/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:28:35 by tiatan            #+#    #+#             */
/*   Updated: 2024/06/17 12:33:18 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// #include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

/* int	main(void)
{
	int result = ft_putchar('0', 0);
	printf("\n%d\n", result);
	return (0);
} */
