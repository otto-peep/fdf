/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:32:09 by pconin            #+#    #+#             */
/*   Updated: 2016/03/21 17:57:33 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
 // keyboard code
#define ESC 53
#define ENTER 36
#define LEFT 123
#define RIGHT 124
#define UP 126
#define DOWN 125
#define Z_PLUS 35
#define Z_LESS 37
#define KEY_C 8

#define SCR_HEIGHT 1000
#define SCR_WIDTH 1000
#define BUFF_SIZE 8
#include "./libft/libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "mlx.h"
#include <fcntl.h>

typedef struct s_env s_env;
typedef struct s_seg s_seg;

typedef struct s_env
{	int			***tmp;
			// en tab_temp[x][y][0] on a l'abscisse x du point et en tab_temp[x][y][1] on a l'ordonnee y du point
			//	on malloc tab_temp en width*len
			//	attention a l'ordre de malloc
			// puis on parse le tableau 1 avec les coordonnees du premier tab on remplit [0] et [1] du second
			// puis on draw le tab_temp
	int			width;
	int			len;
	float		zoom;
	int			**map;
	char		*file;
	// tools for mlx 
	void		*win;
	void		*mlx;
	void		*img_ptr;
	char		*img;
	int			bpp;
	int			endi;
	int			line;
	int			color;
}			t_env;

typedef struct s_seg
{
	int		dx;
	int		dy;
	int		incx;
	int		incy;
	int		inc1;
	int		inc2;
	int		x;
	int		y;
	int		i;
	int		e;
	int		color;
}			t_seg;

// error.c
void		ft_error(char *str);
// file.c
void		open_and_read(char *file, int argc, s_env *stock);
void		ft_readnly(int fd, char **dst, size_t size);
int			ft_open_rdly(char *file);
// tools.c
void		ft_putstr_win(s_env *stock);
void		ft_puttabnbr(int **tab, int len, int width);
// put_in_map.c
int			*parse_line(char *str, int width);
int			ft_tablen(char **tab);
int			ft_foundwidth(char *str);
void		put_in_map(s_env *stock);
//window.c
int			key_h(int keycode, s_env *stock);
void		ft_setwin(s_env *stock);
void		draw_init_window(s_env *stock, int zoom);

// draw.c
void		put_pixel_in_image(int x, int y, s_env *stock, int color);
void		seg_trace_init(int *a, int *b, s_env *stock);
void		seg_trace_1(s_env *stock, s_seg seg);
void		seg_trace_2(s_env *stock, s_seg seg);
void		draw_tab(s_env *stock);
// tab.c
void		ft_init_tab(s_env *stock);
void		ft_free_tab(int ***tab, s_env *stock);
// function.c
void		ft_tab_iso(s_env *stock, int zoom);
void		ft_move_x(s_env *stock, int sign);
void		ft_move_y(s_env *stock, int sign);
void		ft_change_color(s_env *stock);
#endif
