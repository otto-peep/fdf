#include "fdf.h"

void	printline(s_points *line)
{
	while (line->x)
	{
		ft_putnbr(*(line->x));
		line->x++;
	}
}
