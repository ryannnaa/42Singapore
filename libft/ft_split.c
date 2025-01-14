/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:38:47 by tiatan            #+#    #+#             */
/*   Updated: 2024/06/03 16:06:58 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')		
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i + 1] == c)
			count++;
		i++;
	}
	return (count);
}

static	size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' || s[len] != c)
	{
		len++;
	}
	return (len);
}

static	void	array_free(char **dest)
{
	size_t	i;

	i = 0;
	if (dest != NULL)
	{
		while (dest[i] != NULL)
		{
			free(dest[i]);
			i++;
		}
		free(dest);
	}
}

static	char	**array_split(char **dest, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			len = word_len(s + i, c);
			dest[j] = ft_substr(s, i, len);
			if (dest[j] == NULL)
			{
				array_free(dest);
				return (NULL);
			}
		}
		i += len;
		j++;
	}
	dest[j] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	size_t	count;

	count = count_words(s, c);
	dest = (char **)malloc(sizeof(char *) * (count + 1));
	if (dest == NULL)
		return (NULL);
	dest = array_split(dest, s, c);
	return (dest);
}
