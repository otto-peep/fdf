#include "fdf.h"

void	put_pixel_in_image(int x, int y, s_env *stock)
{
	int pl;
	int color;

	pl = (x * 4) + (y * stock->line);
	color = 0xff5ca1;
	stock->img[pl] = color;
}

void	seg_trace_pos(int *a, int *b, s_env *stock)
{
	int dx	;
	int dy;
	int cumul;
	int x;
	int y;

	x = a[0];
	y = a[1];
	dx = b[0] - a[0];
	dy = b[1] - a[1];
	put_pixel_in_image(x, y, stock);
	cumul = dx/2;
	while (x <= b[0] || y <= b[1])
	{
		x++;
		cumul = cumul + dy;
		if (cumul >= dx)
		{
			cumul = cumul + dx;
			y++;
		}
		put_pixel_in_image(x, y, stock);
	}
}
// width est peut etre trop grande (+1 a cause du malloc
void	seg_trace_neg(int *a, int *b, s_env *stock)
{
	int dx;
	int dy;
	int cumul;
	int x;
	int y;

	x = a[0];
	y = a[1];
	dx = b[0] - a[0];
	dy = b[1] - a[1];
	put_pixel_in_image(x, y, stock);
	cumul = dx/2;
	while (x <= b[0] || y >= b[1])
	{
		x++;
		cumul = cumul - dy;
		if (cumul >= dx || a[0] == b[0])
		{
			cumul = cumul - dx;
			y--;
		}
		put_pixel_in_image(x, y, stock);
	}
}
void	seg_trace(int *a, int *b, s_env *stock)
{
	if (a[0] < b[0] && a[1] < b[1])
		seg_trace_pos(a, b, stock);
	else if (a[0] >= b[0] && a[1] <= b[1])
		seg_trace_neg(b, a, stock);
	else if (a[0] <= b[0] && a[1] >= b[1])
		seg_trace_neg(a, b, stock);
	else if (a[0] > b[0] && a[1] > b[1])
		seg_trace_pos(b, a, stock);
}

void	draw_tab(s_env *stock)
{
	int x;
	int y;

	x = 0;
	while (x < (stock->len - 4))
	{
		y = 0;
		while (y < (stock->width - 4))
		{
			//	seg_trace(stock->tmp[x][y], stock->tmp[x][y + 1], stock);
			//	seg_trace(stock->tmp[x][y], stock->tmp[x + 1][y], stock);
			y++;
		}
		x++;
	}
}
