/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 14:02:48 by pconin            #+#    #+#             */
/*   Updated: 2016/04/05 16:34:40 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_tab_iso(t_env *stock, int zoom)
{
	int		x;
	int		y;
	float	f;

	x = 0;
	stock->tmp = (int ***)malloc(sizeof(int **) * (stock->len + 1));
	while (x < stock->len)
	{
		stock->tmp[x] = (int **)malloc(sizeof(int *) * (stock->width + 1));
		y = 0;
		while (y < stock->width)
		{
			stock->tmp[x][y] = (int *)malloc(sizeof(int) * 3);
			stock->tmp[x][y][2] = stock->map[x][y];
			f = (zoom * (stock->rot_x * x + stock->rot_y * y)) + 400;
			stock->tmp[x][y][0] = (int)f;
			f = ((stock->rot_y * (stock->rot_y * x - stock->rot_x * y)) -
					(0.07 * stock->map[x][y])) * zoom + 700;
			stock->tmp[x][y][1] = (int)f;
			y++;
		}
		x++;
	}
}

void	ft_move_x(t_env *stock, int sign)
{
	int x;
	int y;

	x = 0;
	while (x < stock->len)
	{
		y = 0;
		while (y < stock->width)
		{
			stock->tmp[x][y][0] += 100 * sign;
			y++;
		}
		x++;
	}
}

void	ft_move_y(t_env *stock, int sign)
{
	int x;
	int y;

	x = 0;
	while (x < stock->len)
	{
		y = 0;
		while (y < stock->width)
		{
			stock->tmp[x][y][1] += 100 * sign;
			y++;
		}
		x++;
	}
}

void	ft_change_color(t_env *stock)
{
	if (stock->color == 0)
		stock->color = 1;
	else
		stock->color = 0;
}
