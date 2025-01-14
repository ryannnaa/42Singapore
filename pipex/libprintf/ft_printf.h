/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:39:37 by tiatan            #+#    #+#             */
/*   Updated: 2024/06/17 16:39:56 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *input, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbrbase(long n, const char input, unsigned int base);
int	ft_putptr(const char input, unsigned long n);

#endif
