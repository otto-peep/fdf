#include "fdf.h"
#include "mlx.h"

int		key_h(int keycode, void *param)
{
	if (keycode == ESC)
		exit(0);
	ft_putnbr(keycode);
	return (0);
}

void	seg_trace(int xa, int ya, int xb, int yb, void *win, void *mlx)
{
	int dx;
	int dy;
	int cumul;
	int x;
	int y;

	x = xa;
	y = ya;
	dx = xb - xa;
	dy = yb - ya;
	mlx_pixel_put(mlx, win, x, y, 0x00FF00FF);
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
		mlx_pixel_put(mlx, win, x, y, 0x00FF00FF);
	}

}

int		main(void)
{
	void *mlx;
	void *win;
	int width;
	int height;
	void *image;
	int x;
	int y;

	x = 300;
	y = 50;
	width = 100;
	height = 50;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	seg_trace(x, y, 30, 200, win, mlx);
	image = mlx_new_image(mlx, width, height);
	mlx_key_hook(win, &key_h, 0);
	mlx_loop(mlx);
	return (0);
}
