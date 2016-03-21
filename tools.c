/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:49:18 by pconin            #+#    #+#             */
/*   Updated: 2016/03/21 17:01:37 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_puttabnbr(int	**tab, int len, int width)
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

