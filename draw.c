#include "fdf.h"

void	put_pixel_in_image(int x, int y, s_env *stock)
{
	int pl;
	int color;

	pl = (x * 4) + (y * stock->line);
	color = 0xff5ca1;
	stock->img[pl] = color;
}

void	seg_trace(int *a, int *b, s_env *stock)
{
	int dx	;
	int dy;
	int cumul;
	int x;
	int y;

	ft_putnbr(a[0]);
	ft_putchar('\n');
	ft_putnbr(a[1]);
	ft_putchar('\n');
	ft_putnbr(b[0]);
	ft_putchar('\n');
	ft_putnbr(b[1]);
	ft_putchar('\n');
	x = a[0];
	y = a[1];
	dx = b[0] - a[0];
	dy = b[1] - a[1];
	put_pixel_in_image(x, y, stock);
	cumul = dx/2;
	while (x <= b[0])
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

