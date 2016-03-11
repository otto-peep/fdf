/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:55:25 by pconin            #+#    #+#             */
/*   Updated: 2016/03/11 17:15:28 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	put_pixel_in_image(int x, int y, t_stock env)
{
	int pl;
	int color;

	pl = (x * 4) + (y * env.line);
	color = 0xff5ca1;
	pl = 0;
	ft_memcpy(&env.img[pl], &color, env.bpp);
}
