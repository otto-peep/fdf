/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 14:06:02 by pconin            #+#    #+#             */
/*   Updated: 2016/04/05 16:19:57 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rot_x(t_env *stock, int sign)
{
	stock->rot_x += (0.02 * (float)sign);
	ft_free_tab(stock->tmp, stock);
	ft_tab_iso(stock, stock->zoom);
}

void	ft_rot_y(t_env *stock, int sign)
{
	stock->rot_y += (0.02 * (float)sign);
	ft_free_tab(stock->tmp, stock);
	ft_tab_iso(stock, stock->zoom);
}
