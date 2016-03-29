/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 17:34:39 by pconin            #+#    #+#             */
/*   Updated: 2016/03/23 17:33:09 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_tab(int ***tab, s_env *stock)
{
	int x;
	int y;	

	x = 0;
	while(x < stock->len)
	{
		y = 0;
		while (y < stock->width)
		{
			free(tab[x][y]);
			y++;
		}
		free(tab[x]);
		x++;
	}
	free(tab);
}

void	ft_init_tab(s_env *stock)
{
	int x;
	int y;

	x = 0;
	if ((stock->tmp = (int ***) malloc(sizeof (int **) * (stock->len + 1))) == NULL)
		ft_error("malloc error");
	while (x < stock->len)
	{
		if ((stock->tmp[x] = (int **) malloc (sizeof(int *) *(stock->width + 1))) == NULL)
		ft_error("malloc error");
		y = 0;
		while (y < stock->width)
		{
			stock->tmp[x][y] = (int *) malloc (sizeof(int) * 3);
			stock->tmp[x][y][0] = x;
			stock->tmp[x][y][1] = y;
			y++;
		}
		x++;
	}
}

