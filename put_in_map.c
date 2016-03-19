/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:32:03 by pconin            #+#    #+#             */
/*   Updated: 2016/03/19 17:41:19 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*parse_line(char *str)
{
	int		*line;
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit(str, ' ');
	line = (int *)malloc(sizeof (int) * (ft_tablen(tab)));
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
	while(tab[len])
		len++;
	return (len);
}

void	put_in_map(s_env *stock)
{
	int		larg;
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit(stock->file, '\n');
	stock->map = (int **)malloc(sizeof (int *) * (stock->len = ft_tablen(tab)));
	while (tab[i])
	{
		stock->map[i] = parse_line(tab[i]);
		i++;
	}
}
