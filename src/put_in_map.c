/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:32:03 by pconin            #+#    #+#             */
/*   Updated: 2016/09/15 15:09:04 by pconin           ###   ########.fr       */
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
	if ((line = (int *)malloc(sizeof(int) * (width + 1))) == NULL)
		ft_error("error malloc");
	line = ft_memset(line, 0, width + 1);
	while (tab[i])
	{
		line[i] = ft_atoi(tab[i]);
		i++;
	}
	return (line);
}

int		ft_tablen(char **tab)
{
	int	len;

	len = 0;
	while (tab[len])
	{
		len++;
		if (len > 10000)
			ft_error("file error : len > 10000");
	}
	return (len);
}

int		ft_foundwidth(char *str)
{
	int			i;
	static int	w = 0;
	char		**tab;

	i = 0;
	tab = ft_strsplit(str, ' ');
	while (tab[i])
	{
		i++;
		if (i > 10000)
			ft_error("file error : width > 10000");
	}
	if (i > w)
		w = i;
	return (w);
}

void	put_in_map(t_env *stock)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit(stock->file, '\n');
	stock->len = ft_tablen(tab);
	stock->map = (int **)malloc(sizeof(int *) * (stock->len + 1));
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
