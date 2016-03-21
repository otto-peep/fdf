#include "fdf.h"

void	draw_init_window(s_env *stock)
{
	ft_free_tab(stock->tmp, stock);
	ft_init_tab(stock);
}

int		key_h(int keycode, void *stock)
{
	if (keycode == ENTER)
		draw_init_window(stock);
	if (keycode == ESC)
		exit(0);
	ft_putstr("\n keycode :");
	ft_putnbr(keycode);
	return (0);
}

void	ft_setwin(s_env *stock)
{
	stock->bpp = 0;
	stock->line = 0;
	stock->endi = 0;
	ft_init_tab(stock);
	stock->mlx = mlx_init();
	stock->win = mlx_new_window(stock->mlx, 600, 600, "Fil de Fer 42");
	stock->img_ptr = mlx_new_image(stock->mlx, 600, 600);
	stock->img = mlx_get_data_addr(stock->img_ptr, &(stock->bpp), &(stock->line), &(stock->endi));
	seg_trace(stock->tmp[2][3], stock->tmp[4][4], stock);
	mlx_put_image_to_window(stock->mlx, stock->win, stock->img_ptr, 10, 10);
	mlx_key_hook(stock->win, &key_h, stock);
	mlx_loop(stock->mlx);
}
