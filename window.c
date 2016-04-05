#include "fdf.h"

void	draw_init_window(s_env *stock, int zoom)
{
	ft_free_tab(stock->tmp, stock);
	ft_tab_iso(stock, zoom);
}

int		key_h(int keycode, s_env *stock)
{
	stock->img_ptr = mlx_new_image(stock->mlx, SCR_WIDTH, SCR_HEIGHT);
	stock->img = mlx_get_data_addr(stock->img_ptr, &(stock->bpp), &(stock->line), &(stock->endi));
	if (keycode == ENTER)
		draw_init_window(stock, (stock->zoom = 4));
	if (keycode == ESC)
		exit(0);
	if (keycode == LEFT)
		ft_move_x(stock, -1);
	if (keycode == RIGHT)
		ft_move_x(stock, 1);
	if (keycode == UP)
		ft_move_y(stock, -1);
	if (keycode == DOWN)
		ft_move_y(stock, 1);
	if (keycode == Z_PLUS)
		draw_init_window(stock, stock->zoom++);
	if (keycode == Z_LESS)
		draw_init_window(stock, stock->zoom--);
	if (keycode == KEY_C)
		ft_change_color(stock);
	ft_putstr_win(stock);
	ft_putstr("\n keycode :");
	ft_putnbr(keycode);
	key_h2(keycode, stock);
	return (0);
}

void	key_h2(int keycode, s_env *stock)
{
	if (keycode == ROTX_PLUS)
		ft_rot_x(stock, 1);
	if (keycode == ROTX_LESS)
		ft_rot_x(stock, -1);
	if (keycode == ROTY_PLUS)
		ft_rot_y(stock, 1);
	if (keycode == ROTY_LESS)
		ft_rot_y(stock, -1);
	draw_tab(stock);
	mlx_put_image_to_window(stock->mlx, stock->win, stock->img_ptr, 0, 0);
	ft_putstr_win(stock);
}

void	ft_setwin(s_env *stock)
{
	stock->rot_x = 0.45;
	stock->rot_y = 0.7;
	stock->bpp = 0;
	stock->line = 0;
	stock->endi = 0;
	stock->zoom = 4;
	stock->color = 0;
	ft_init_tab(stock);
	stock->mlx = mlx_init();
	stock->win = mlx_new_window(stock->mlx, SCR_WIDTH, SCR_HEIGHT, "Fil de Fer 42");
	stock->img_ptr = mlx_new_image(stock->mlx, SCR_WIDTH, SCR_HEIGHT);
	stock->img = mlx_get_data_addr(stock->img_ptr, &(stock->bpp), &(stock->line), &(stock->endi));
	mlx_string_put (stock->mlx, stock->win, 300, 300, 0xffffff, "Press ENTER to init" );
	mlx_key_hook(stock->win, &key_h, stock);
	mlx_loop(stock->mlx);
}
