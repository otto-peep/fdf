#include "fdf.h"

void	ft_rot_x(s_env *stock, int sign)
{
	stock->rot_x += (0.02 * (float) sign);
	ft_free_tab(stock->tmp, stock);
	ft_tab_iso(stock, stock->zoom);
}

void	ft_rot_y(s_env *stock, int sign)
{
	stock->rot_y += (0.02 * (float) sign);
	ft_free_tab(stock->tmp, stock);
	ft_tab_iso(stock, stock->zoom);
}

