/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:49:18 by pconin            #+#    #+#             */
/*   Updated: 2016/04/05 16:20:17 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_puttabnbr(int **tab, int len, int width)
{
	int i;
	int y;

	i = 0;
	while (i < len)
	{
		y = 0;
		while (y < width)
		{
			ft_putnbr(tab[i][y]);
			y++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	ft_putstr_win(t_env *stock)
{
	mlx_string_put(stock->mlx, stock->win, 10, 10, 0xffffff, "Move = arrows");
	mlx_string_put(stock->mlx, stock->win, 10, 25, 0xffffff, "Reinit = enter");
	mlx_string_put(stock->mlx, stock->win, 10, 40, 0xffffff, "Zoom + = 'P'");
	mlx_string_put(stock->mlx, stock->win, 10, 55, 0xffffff, "Zoom - = 'L'");
	mlx_string_put(stock->mlx, stock->win, 200, 10, 0xffffff, "Color = 'C'");
	mlx_string_put(stock->mlx, stock->win, 200, 25, 0xffffff,
			"Horizontal rotation = 'F' / 'D'");
	mlx_string_put(stock->mlx, stock->win, 200, 40, 0xffffff,
			"Vertical rotation = 'R' / 'E'");
}
