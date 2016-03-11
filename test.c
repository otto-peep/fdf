/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 14:21:47 by pconin            #+#    #+#             */
/*   Updated: 2016/03/11 18:03:39 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	seg_trace(int xa, int ya, int xb, int yb, t_stock env)
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
	put_pixel_in_image(x, y, env);
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
		put_pixel_in_image(x, y, env);
	}

}

int		main(void)
{
	int height;
	t_stock env;
	int a;
	a = 0;
	int color = 0xFFFFFF;
	env.width = 500;
	height = 500;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 600, 600, "mlx 42");
	env.img_ptr = mlx_new_image(env.mlx, env.width, height);
	env.line = env.width;
	env.img = mlx_get_data_addr(env.img_ptr, &(env.bpp), &(env.line), &(env.endi));
	seg_trace(10, 10, 400, 400, env);
	mlx_put_image_to_window(env.mlx, env.win, env.img_ptr, 10, 10);
	mlx_key_hook(env.win, &key_h, 0);
	mlx_loop(env.mlx);
	return (0);
}
