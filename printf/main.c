/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:21:47 by tiatan            #+#    #+#             */
/*   Updated: 2024/07/26 17:26:23 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> 
#include <limits.h>

// For comparison with the standard printf
int main(void)
{
    int len1, len2;
    // Test with character
    len1 = ft_printf("Character: %c\n", 'A');
    len2 = printf("Character: %c\n", 'A');
    printf("ft_printf length: %d, printf length: %d\n", len1, len2);
    // Test with string
    len1 = ft_printf("String: %s\n", "Hello, World!");
    len2 = printf("String: %s\n", "Hello, World!");
    printf("ft_printf length: %d, printf length: %d\n", len1, len2);
    // Test with null string
    len1 = ft_printf("Null String: %s\n", (char *)NULL);
    len2 = printf("Null String: %s\n", (char *)NULL);
    printf("ft_printf length: %d, printf length: %d\n", len1, len2);
    // Test with pointer
    int a = 42;
    int *ptr = &a;
    len1 = ft_printf("Pointer: %p\n", (void *)ptr);
    len2 = printf("Pointer: %p\n", (void *)ptr);
    printf("ft_printf length: %d, printf length: %d\n", len1, len2);
    // Test with decimal and integer
    len1 = ft_printf("Decimal: %d, Integer: %i\n", 123, -456);
    len2 = printf("Decimal: %d, Integer: %i\n", 123, -456);
    printf("ft_printf length: %d, printf length: %d\n", len1, len2);
    // Test with unsigned integer
    len1 = ft_printf("Unsigned: %u\n", -1);
    len2 = printf("Unsigned: %u\n", -1);
    printf("ft_printf length: %d, printf length: %d\n", len1, len2);
    // Test with hexadecimal (lowercase)
    len1 = ft_printf("Hexadecimal (lowercase): %x\n", 0xABCDEF);
    len2 = printf("Hexadecimal (lowercase): %x\n", 0xABCDEF);
    printf("ft_printf length: %d, printf length: %d\n", len1, len2);
    // Test with hexadecimal (uppercase)
    len1 = ft_printf("Hexadecimal (uppercase): %X\n", 0xABCDEF);
    len2 = printf("Hexadecimal (uppercase): %X\n", 0xABCDEF);
    printf("ft_printf length: %d, printf length: %d\n", len1, len2);
    // Test with percentage sign
    len1 = ft_printf("Percentage: %%\n");
    len2 = printf("Percentage: %%\n");
    printf("ft_printf length: %d, printf length: %d\n", len1, len2);
    return 0;
}
