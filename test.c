/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 14:21:47 by pconin            #+#    #+#             */
/*   Updated: 2016/03/10 15:24:45 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

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
	int width;
	int height;
	t_stock env;


	width = 100;
	height = 50;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 400, 400, "mlx 42");
	env.img_ptr = mlx_new_image(env.mlx, width, height);
	env.img = mlx_get_data_addr(env.img_ptr, env.bpp, env.line, env.endi);
	put_pixel_in_image(19, 25, env);
	mlx_put_image_to_window(env.mlx, env.win, env.img_ptr, 10, 10);
	mlx_key_hook(env.win, &key_h, 0);
	mlx_loop(env.mlx);
	return (0);
}
