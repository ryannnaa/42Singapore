/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:38:47 by tiatan            #+#    #+#             */
/*   Updated: 2024/10/03 17:18:30 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static	int	word_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			count++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	return (count);
}

static	size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

static	void	array_free(char **dest)
{
	char	**temp;

	temp = dest;
	if (temp != NULL)
	{
		while (*temp != NULL)
		{
			free(*temp);
			temp++;
		}
		free(dest);
	}
}

static	char	**word_split(char const *s, char c, char **dest)
{
	size_t	len;
	int		s_count;

	s_count = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			len = word_len(s, c);
			*(dest + s_count) = ft_substr(s, 0, len);
			if (*(dest + s_count) == NULL)
			{
				array_free(dest);
				return (NULL);
			}
			s_count++;
			s += len;
		}
	}
	dest[s_count] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		count;

	count = word_count(s, c);
	dest = (char **)malloc(sizeof(char *) * (count + 1));
	if (dest == NULL)
		return (NULL);
	dest = word_split(s, c, dest);
	return (dest);
}
/*
int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Usage: %s <string> <delimiter>\n", argv[0]);
		return (1); // Indicate error
	}

	char **result = ft_split(argv[1], *argv[2]);
	if (result != NULL)
	{
		for (int i = 0; result[i] != NULL; i++)
		{
			printf("%s\n", result[i]);
			free(result[i]);
		}
		free(result); // Free the array itself
	}

	return (0);
}*/

// int	main(int argc, char **argv)
// {
// 	char	*str;
// 	char	**strarray;
// 	size_t i;

// 	i = 0;
// 	str = argv[1];
// 	strarray = ft_split(str, argv[2][0]);
// 	printf("-----------------------------\n");
// 	printf("The Input is: %s\n", argv[1]);
// 	printf("The Delimiter is: %s\n", argv[2]);
// 	printf("Number of substrings: %ld\n", (word_count((char *)str,
// 				argv[2][0])));
// 	while (i < (word_count((char *)str, argv[2][0])))
// 	{
// 		printf("The %d element in the array is: %s\n", i, strarray[i]);
// 		free(strarray[i]);
// 		i++;
// 	}
// 	free(strarray);
// 	printf("-----------------------------\n");
// 	return (0);
// }

// int	main(void)
// {
// 	size_t	i;
// 	char	*str;
// 	char	**strarray;
// 	char	c = ' ';

// 	str = "hello!";
// 	strarray = ft_split("^^^1^^2a,^^^^3^^^^--h^^^^", '^');
// 	array_free(strarray);
// 	return (0);
// }
