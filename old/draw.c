/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:55:25 by pconin            #+#    #+#             */
/*   Updated: 2016/03/21 17:02:12 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	put_pixel_in_image(int x, int y, t_stock env)
{
	int pl;
	int color;

	pl = (x * 4) + (y * env.line);
	color = 0xff5ca1;
	env.img[pl] = color;
}

void	seg_trace_pos(int xa, int ya, int xb, int yb, t_stock env)
{
	int dx;
	int dy;
	int cumul;
	int x;
	int y;

	x = xa;
	y = ya;
	dx = xb - xa;
	dy = yb - ya;
	put_pixel_in_image(x, y, env);
	cumul = dx/2;
	while (x <= xb)
	{
		x++;
		cumul = cumul + dy;
		if (cumul >= dx)
		{
			cumul = cumul + dx;
			y++;
		}
		put_pixel_in_image(x, y, env);
	}
}

void	seg_trace_neg(int xa, int ya, int xb, int yb, t_stock env)
{
	int dx;
	int dy;
	int cumul;
	int x;
	int y;

	x = xa;
	y = ya;
	dx = xb - xa;
	dy = yb - ya;
	put_pixel_in_image(x, y, env);
	cumul = dx/2;
	while (x <= xb)
	{
		x++;
		cumul = cumul - dy;
		if (cumul >= dx)
		{
			cumul = cumul - dx;
			y--;
		}
		put_pixel_in_image(x, y, env);
	}
}

void	seg_trace(int xa, int ya, int xb, int yb, t_stock env)
{
	if (xa < xb && ya < yb)
		seg_trace_pos(xa, ya, xb, yb, env);
	else if (xa > xb && ya < yb)
		seg_trace_neg(xb, yb, xa, ya, env);
	else if (xa < xb && ya > yb)
		seg_trace_neg(xa, ya, xb, yb, env);
	else if (xa > xb && ya > yb)
		seg_trace_pos(xb, yb, xa, ya, env);
}
