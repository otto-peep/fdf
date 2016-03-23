/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:32:03 by pconin            #+#    #+#             */
/*   Updated: 2016/03/21 17:57:49 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*parse_line(char *str, int width)
{
	int		*line;
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit(str, ' ');
	line = (int *)malloc(sizeof (int) * (width + 1));
	line = ft_memset(line, 0, width + 1);
	while (tab[i])
	{
		line[i] = (100 * ft_atoi(tab[i]));
		i++;
	}
	return (line);
}

int		ft_tablen(char **tab)
{
	int	len;

	len = 0;
	while(tab[len])
	{
		len++;
	}
	return (len);
}

int		ft_foundwidth(char *str)
{
	int i;
	static int w = 0;
	char **tab;

	i = 0;
	tab = ft_strsplit(str, ' ');
	while (tab[i])
		i++;
	if (i > w)
		w = i;
	return (w);
}

void	put_in_map(s_env *stock)
{
	int		larg;
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit(stock->file, '\n');
	stock->len = ft_tablen(tab);
	stock->map = (int **)malloc(sizeof (int *) * (stock->len + 1));
	while (tab[i])
	{
		stock->width = ft_foundwidth(tab[i]);
		i++;
	}
	i = 0;
	while (tab[i])
	{
		stock->map[i] = parse_line(tab[i], stock->width);
		i++;
	}
}
