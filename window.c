#include "fdf.h"

int		key_h(int keycode, void *stock)
{
	if (keycode == ESC)
		exit(0);
	ft_putstr("\n keycode :");
	ft_putnbr(keycode);
	return (0);
}

void	ft_setwin(s_env *stock)
{
	
	stock->mlx = mlx_init();
	stock->win = mlx_new_window(stock->mlx, 1000, 1000, "Fil de Fer 42");
	stock->img_ptr = mlx_new_image(stock->mlx, (stock->width * 2), (stock->len * 2));
	stock->img = mlx_get_data_addr(stock->img_ptr, &(stock->bpp), &(stock->line), &(stock->endi));
	seg_trace(10, 10, 400, 400, stock);
	mlx_put_image_to_window(stock->mlx, stock->win, stock->img_ptr, 10, 10);
	mlx_key_hook(stock->win, &key_h, stock);
	mlx_loop(stock->mlx);
}
