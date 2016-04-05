/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:32:09 by pconin            #+#    #+#             */
/*   Updated: 2016/04/05 14:38:38 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# define ESC 53
# define ENTER 36
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define Z_PLUS 35
# define Z_LESS 37
# define KEY_C 8
# define ROTX_PLUS 15
# define ROTX_LESS 14
# define ROTY_PLUS 3
# define ROTY_LESS 2
# define SCR_HEIGHT 1200
# define SCR_WIDTH 2400
# define BUFF_SIZE 8
# include "./libft/libft.h"
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

typedef struct s_env	s_env;
typedef struct s_seg	s_seg;

typedef struct	s_env
{	int			***tmp;
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
	float		rot_x;
	float		rot_y;
}			t_env;

typedef struct	s_seg
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
void		key_h2(int keycode, s_env *stock);
void		ft_setwin(s_env *stock);
void		draw_init_window(s_env *stock, int zoom);

// draw.c
void		put_pixel_in_image(int x, int y, s_env *stock, int color);
void		seg_trace_init(int *a, int *b, s_env *stock);
void		seg_trace_1(s_env *stock, s_seg seg);
void		seg_trace_2(s_env *stock, s_seg seg);
// tab.c
void		draw_tab(s_env *stock);
void		ft_init_tab(s_env *stock);
void		ft_free_tab(int ***tab, s_env *stock);
// function.c
void		ft_tab_iso(s_env *stock, int zoom);
void		ft_move_x(s_env *stock, int sign);
void		ft_move_y(s_env *stock, int sign);
void		ft_change_color(s_env *stock);
// rot.c
void		ft_rot_x(s_env *stock, int sign);
void		ft_rot_y(s_env *stock, int sign);

#endif
