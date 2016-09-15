/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:32:09 by pconin            #+#    #+#             */
/*   Updated: 2016/09/15 15:08:49 by pconin           ###   ########.fr       */
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
# define BUF_SIZE 100
# include "../libft/libft.h"
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

typedef struct	s_env
{
	int			***tmp;
	int			width;
	int			len;
	float		zoom;
	int			**map;
	char		*file;
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
}				t_env;

typedef struct	s_seg
{
	int			dx;
	int			dy;
	int			incx;
	int			incy;
	int			inc1;
	int			inc2;
	int			x;
	int			y;
	int			i;
	int			e;
	int			color;
}				t_seg;

void			ft_error(char *str);
void			open_and_read(char *file, int argc, t_env *stock);
void			ft_readnly(int fd, char **dst, size_t size);
int				ft_open_rdly(char *file);
void			ft_putstr_win(t_env *stock);
void			ft_puttabnbr(int **tab, int len, int width);
int				*parse_line(char *str, int width);
int				ft_tablen(char **tab);
int				ft_foundwidth(char *str);
void			put_in_map(t_env *stock);
int				key_h(int keycode, t_env *stock);
void			key_h2(int keycode, t_env *stock);
void			ft_setwin(t_env *stock);
void			draw_init_window(t_env *stock, int zoom);
void			put_pixel_in_image(int x, int y, t_env *stock, int color);
void			seg_trace_init(int *a, int *b, t_env *stock);
void			seg_trace_1(t_env *stock, t_seg seg);
void			seg_trace_2(t_env *stock, t_seg seg);
void			draw_tab(t_env *stock);
void			ft_init_tab(t_env *stock);
void			ft_free_tab(int ***tab, t_env *stock);
void			ft_tab_iso(t_env *stock, int zoom);
void			ft_move_x(t_env *stock, int sign);
void			ft_move_y(t_env *stock, int sign);
void			ft_change_color(t_env *stock);
void			ft_rot_x(t_env *stock, int sign);
void			ft_rot_y(t_env *stock, int sign);

#endif
