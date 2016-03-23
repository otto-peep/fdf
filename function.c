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
