/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 14:11:33 by pconin            #+#    #+#             */
/*   Updated: 2016/04/05 16:27:00 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel_in_image(int x, int y, t_env *stock, int color)
{
	int pl;
	int octet;

	octet = stock->bpp / 8;
	pl = (x * (stock->bpp / 8)) + (y * stock->line);
	if (x >= 0 && y >= 0 && x < SCR_WIDTH && y < SCR_HEIGHT)
		ft_memcpy(&stock->img[pl], &color, octet);
	else
		return ;
}

int		find_color(int za, int zb, int color)
{
	int d;

	d = za - zb;
	if (color == 0)
		return (0x0033CC33);
	else
	{
		if (d < 0)
			d = -d;
		if (d == 0)
			return (0x00CC9900);
		else if (d == 1)
			return (0x00CC6600);
		else if (d == 2)
			return (0x00CC3300);
		else if (d >= 3 && d <= 4)
			return (0x00CC0000);
		else if (d >= 5 && d <= 6)
			return (0x00990000);
		else if (d >= 7 && d <= 9)
			return (0x00660033);
		else
			return (0x00660000);
	}
}

void	seg_trace_init(int *a, int *b, t_env *stock)
{
	t_seg seg;

	seg.color = find_color(a[2], b[2], stock->color);
	if ((seg.dx = b[0] - a[0]) < 0)
		seg.dx = -seg.dx;
	if ((seg.dy = b[1] - a[1]) < 0)
		seg.dy = -seg.dy;
	seg.incx = 1;
	if (b[0] < a[0])
		seg.incx = -1;
	seg.incy = 1;
	if (b[1] < a[1])
		seg.incy = -1;
	seg.x = a[0];
	seg.y = a[1];
	seg_trace_1(stock, seg);
}

void	seg_trace_1(t_env *stock, t_seg seg)
{
	if (seg.dx > seg.dy)
	{
		put_pixel_in_image(seg.x, seg.y, stock, seg.color);
		seg.e = 2 * seg.dy - seg.dx;
		seg.inc1 = 2 * (seg.dy - seg.dx);
		seg.inc2 = 2 * seg.dy;
		seg.i = 0;
		while (seg.i < seg.dx)
		{
			if (seg.e >= 0)
			{
				seg.y = seg.incy + seg.y;
				seg.e = seg.inc1 + seg.e;
			}
			else
				seg.e = seg.inc2 + seg.e;
			seg.x = seg.incx + seg.x;
			put_pixel_in_image(seg.x, seg.y, stock, seg.color);
			seg.i++;
		}
	}
	else
		seg_trace_2(stock, seg);
}

void	seg_trace_2(t_env *stock, t_seg seg)
{
	put_pixel_in_image(seg.x, seg.y, stock, seg.color);
	seg.e = 2 * seg.dx - seg.dy;
	seg.inc1 = 2 * (seg.dx - seg.dy);
	seg.inc2 = 2 * seg.dx;
	seg.i = 0;
	while (seg.i < seg.dy)
	{
		if (seg.e >= 0)
		{
			seg.x = seg.incx + seg.x;
			seg.e = seg.inc1 + seg.e;
		}
		else
			seg.e = seg.inc2 + seg.e;
		seg.y = seg.y + seg.incy;
		put_pixel_in_image(seg.x, seg.y, stock, seg.color);
		seg.i++;
	}
}
