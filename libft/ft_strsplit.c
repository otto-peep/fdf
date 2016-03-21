/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 14:53:58 by pconin            #+#    #+#             */
/*   Updated: 2016/03/18 02:29:04 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static 		size_t ft_wordscount(char *s, char c)
{
	size_t nb;

	while (*s && *s == c)
		s++;
	nb = (*s ? 1 : 0);
	while (				*s)
	{
		if (*s == c && *(s + 1) && *(s + 1) != c)
			nb++;
		s++;
	}
	return (nb);
}

char**ft_strsplit(char const *s, char c)
{
	size_t	words;
	char	*start;
	char	**result;

	if (s == NULL)
		return (NULL);
	words = ft_wordscount((char *)s, c);
	if (!(result = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	start = (char *)s;
	while (*s)
	{
		if (*s == c)
		{
			if (start != s)
				*(result++) = ft_strsub(start, 0, s - start);
			start = (char *)s + 1;
		}
		s++;
	}
	if (start != s)
		*(result++) = ft_strsub(start, 0, s - start);
	*result = NULL;
	return (result - words);
}
