#include "fdf.h"

void	put_pixel_in_image(int x, int y, s_env *stock)
{
	int pl;
	int color;

	pl = (x * 4) + (y * stock->line);
	color = 0x1984aa;
	stock->img[pl] = color;
}

void	seg_trace(int *a, int *b, s_env *stock)
{
	int dx;
	int dy;
	int incx, incy, inc1, inc2;
	int x, y;
	int i, e;
	if ((dx = b[0] - a[0]) < 0)
		dx = -dx;
	if ((dy = b[1] - a[1]) < 0)
		dy = -dy;
	incx = 1;
	if (b[0] < a[0])
		incx = -1;
	incy = 1;
	if (b[1] < a[1])
		incy = -1;
	x = a[0];
	y = a[1];
	if (dx > dy)
	{
		put_pixel_in_image(x, y, stock);
		e = 2 * dy - dx;
		inc1 = 2 * (dy - dx);
		inc2 = 2 *dy;
		i = 0;
		while (i < dx)
		{
			if (e >= 0)
			{
				y = incy + y;
				e = inc1 + e;
			}
			else
				e = inc2+ e;
			x = incx + x;
			put_pixel_in_image(x, y, stock);
			i++;
		}
	}
	else
	{
		put_pixel_in_image(x, y, stock);
		e = 2*dx - dy;
		inc1 = 2*(dx - dy);
		inc2 = 2 * dx;
		i = 0;
		while (i < dy)
		{
			if (e >= 0)
			{
				x = incx + x;
				e = inc1 + e;
			}
			else
				e = inc2 + e;
			y = y + incy;
			put_pixel_in_image(x, y, stock);
			i++;
		}
	}
}

void	draw_tab(s_env *stock)
{
	int x;
	int y;

	x = 0;
	while (x < (stock->len))
	{
		y = 0;
		while (y < (stock->width))
		{
			if (x < (stock->len - 1))
				seg_trace(stock->tmp[x][y], stock->tmp[x + 1][y], stock);
			if (y < (stock->width - 1))
				seg_trace(stock->tmp[x][y], stock->tmp[x][y + 1], stock);
			y++;
		}
		x++;
	}
}
