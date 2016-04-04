#include "fdf.h"

void	put_pixel_in_image(int x, int y, s_env *stock, int color)
{
	int pl;

	pl = (x * 4) + (y * stock->line);

	if (x >= 0 && y >= 0 && x < SCR_WIDTH && y < SCR_HEIGHT)
		stock->img[pl] = color;
	else
		return ;
}

int		find_color(int za, int zb, int color)
{
	int d;
	
	d = za - zb;
	if (color == 0)
		return (0xCCCCCC);
	else
		return (0x00ffffff);
/*	else
	{
	if (d < 0)
		d = -d;
	if (d == 0)
		return (0x00ffffff);
	else if (d == 1)
		return (0x00ffff66);
	else if (d > 1 && d < 3)
		return (0x00ff9900);
	else if (d >= 3 && d < 6)
		return (0x00ff3300);
	else
		return (0x00ff0000);
	}	*/
}

void	seg_trace_init(int *a, int *b, s_env *stock)
{
	s_seg seg;
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

void	seg_trace_1(s_env *stock, s_seg seg)
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
				seg.e = seg.inc2+ seg.e;
			seg.x = seg.incx + seg.x;
			put_pixel_in_image(seg.x, seg.y, stock, seg.color);
			seg.i++;
		}
	}
	else
		seg_trace_2(stock, seg);
}
void	seg_trace_2(s_env *stock, s_seg seg)
{
	put_pixel_in_image(seg.x, seg.y, stock, seg.color);
	seg.e = 2*seg.dx - seg.dy;
	seg.inc1 = 2*(seg.dx - seg.dy);
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
				seg_trace_init(stock->tmp[x][y], stock->tmp[x + 1][y], stock);
			if (y < (stock->width - 1))
				seg_trace_init(stock->tmp[x][y], stock->tmp[x][y + 1], stock);
			y++;
		}
		x++;
	}
}
