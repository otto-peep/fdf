#include "fdf.h"

void	put_pixel_in_image(int x, int y, s_env *stock)
{
	int pl;
	int color;

	pl = (x * 4) + (y * stock->width);
	color = 0xff5ca1;
	stock->img[pl] = color;
}

void	seg_trace(int xa, int ya, int xb, int yb, s_env *stock)
{
	int dx	;
	int dy;
	int cumul;
	int x;
	int y;

	x = xa;
	y = ya;
	dx = xb - xa;
	dy = yb - ya;
	put_pixel_in_image(x, y, stock);
	cumul = dx/2;
	while (x <= xb)
	{
		x++;
		cumul = cumul + dy;
		if (cumul >= dx)
		{
			cumul = cumul - dx;
			y++;
		}
		put_pixel_in_image(x, y, stock);
	}
}
// width est peut etre trop grande (+1 a cause du malloc
