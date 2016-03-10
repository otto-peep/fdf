#ifndef FDF_H

#define FDF_H
#define ESC 53
#include "./libft/libft.h"
#include <stdlib.h>
#include <string.h>

typedef struct s_env
{
	void			*win;
	void			*mlx;
	char			*img;
	void			*img_ptr;
	int				*line;
	int				*bpp;
	int				*endi;
	struct s_env	*next;
}				t_stock;

int			key_h(int keycode, void *param);
void		put_pixel_in_image(int x, int y, t_stock env);

#endif
