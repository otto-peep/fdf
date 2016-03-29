#include "fdf.h"

void	ft_tab_iso(s_env *stock)
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
			f = 15. + (35. + 4) * (0.82 * x + 0.57 * y);
			stock->tmp[x][y][0] =  (int)(f + 0.5) + 200;
			f = 0.57 * (0.57 * x - 0.82 * y);
			ft_putstr("\n");
			ft_putnbr(stock->map[x][y]);
			ft_putstr("\n");
			f -= 0.06 * stock->map[x][y];
			f *= (35. + 4);
			f += 533;
			stock->tmp[x][y][1] = (int) (f + 0.5) + 200; 
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

	if (stock->tmp[0][0][1] > (SCR_HEIGHT - 300) && sign == 1)
		return ;
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
