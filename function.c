#include "fdf.h"

void	ft_tab_iso(s_env *stock, int zoom)
{
	int x;
	int y;
	float f;

	x = 0;
	stock->tmp = (int ***) malloc(sizeof (int **) * (stock->len + 1));
	while (x < stock->len)
	{
		stock->tmp[x] = (int **) malloc (sizeof(int *) *(stock->width + 1));
		y = 0;
		while (y < stock->width)
		{
			stock->tmp[x][y] = (int *) malloc (sizeof(int) * 3);
			f = 15. + (35. + zoom) * (stock->rot_x * x + stock->rot_y * y);
			stock->tmp[x][y][0] =  (int)(f + 0.5) + 200;
			f = stock->rot_y * (stock->rot_y * x - stock->rot_x * y);
			f -= 0.06 * stock->map[x][y];
			f *= (35. + zoom);
			stock->tmp[x][y][1] = (int) (f + 0.5) + 700; 
			y++;
		}
		x++;
	}
}

void	ft_move_x(s_env *stock, int sign)
{
	int x;
	int y;

	x = 0;
	while (x < stock->len)
	{
		y = 0;
		while (y < stock->width)
		{
			stock->tmp[x][y][0] += 100 * sign;
			y++;
		}
		x++;
	}
}

void	ft_move_y(s_env *stock, int sign)
{
	int x;
	int y;

	x = 0;
	while (x < stock->len)
	{
		y = 0;
		while (y < stock->width)
		{
			stock->tmp[x][y][1] += 100 * sign;
			y++;
		}
		x++;
	}
}

void	ft_change_color(s_env *stock)
{
	if (stock->color == 0)
		stock->color = 1;
	else
		stock->color = 0;
}
