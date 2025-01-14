/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:35:55 by tiatan            #+#    #+#             */
/*   Updated: 2024/11/04 00:37:33 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	c_result(const char *nptr, unsigned long *result, int sign)
{
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (*result > (ULONG_MAX - (*nptr - '0')) / 10 || *result / 10 > (ULONG_MAX / 10 - (*nptr - '0')))
		{
			*result = LONG_MAX;
			return (0);
		}
		*result = *result * 10 + (*nptr - '0');
		nptr++;
	}
	*result *= sign;
	return (0);
}

long	ft_atol(const char *nptr)
{
	unsigned long	result;
	int				sign;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\t' || *nptr == '\v'
		|| *nptr == '\f' || *nptr == '\r')
		nptr++;
	while (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	if (c_result(nptr, &result, sign))
		return (result);
	return (result);
}
