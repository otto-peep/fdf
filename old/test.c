/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 14:21:47 by pconin            #+#    #+#             */
/*   Updated: 2016/03/21 16:38:04 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int		main(int argc, char **argv)
{
	int height;
	t_stock env;
	int a;
	a = 0;
	int color = 0xFFFFFF;
	env.width = 500;
	height = 500;
	s_points *line;

//	if (argc != 2)
//		ft_error("wrong number of argument");
//	line = file_treat(argv[1]);
//	while (line)
//	{
//		printline(line);
//		line = line->next;
//	}

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 600, 600, "mlx 42");
	env.img_ptr = mlx_new_image(env.mlx, env.width, height);
	env.line = env.width;
	env.img = mlx_get_data_addr(env.img_ptr, &(env.bpp), &(env.line), &(env.endi));
	seg_trace(10, 10, 400, 400, env);
	ft_putnbr(env.line);
	ft_putchar('\n');
	ft_putnbr(env.bpp);
	ft_putchar('\n');
	ft_putnbr(env.endi);
	ft_putchar('\n');
	mlx_put_image_to_window(env.mlx, env.win, env.img_ptr, 10, 10);
	mlx_key_hook(env.win, &key_h, 0);
	mlx_loop(env.mlx);
	return (0);
}

