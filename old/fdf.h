#ifndef FDF_H

#define FDF_H
#define ESC 12
#define BUF_SIZE 8
#include "./libft/libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "mlx.h"

typedef struct s_points s_points;

typedef struct s_env
{
	int				width;
	void			*win;
	void			*mlx;
	char			*img;
	void			*img_ptr;
	int				line;
	int				bpp;
	int				endi;
}				t_stock;

struct s_points
{
	int				size_line;
	int				*x;
	struct s_points	*next;
}					t_points;

int			key_h(int keycode, void *param);
void		put_pixel_in_image(int x, int y, t_stock env);
void		seg_trace(int xa, int ya, int xb, int yb, t_stock env);
void		ft_open_rdly(char *file);
void		ft_error(char *str);
void		ft_newline(s_points *line, char *temp);
s_points	*file_treat(char *file);
void		printline(s_points *line);

#endif
