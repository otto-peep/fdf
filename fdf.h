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

#define BUFF_SIZE 8
#include "./libft/libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "mlx.h"
#include <fcntl.h>

typedef struct s_env s_env;

typedef struct s_env
{	int			***tmp;
			// en tab_temp[x][y][0] on a l'abscisse x du point et en tab_temp[x][y][1] on a l'ordonnee y du point
			//	on malloc tab_temp en width*len
			//	attention a l'ordre de malloc
			// puis on parse le tableau 1 avec les coordonnees du premier tab on remplit [0] et [1] du second
			// puis on draw le tab_temp
	int			width;
	int			len;
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
}			t_env;

// error.c
void		ft_error(char *str);
// file.c
void		open_and_read(char *file, int argc, s_env *stock);
void		ft_readnly(int fd, char **dst, size_t size);
int			ft_open_rdly(char *file);
// tools.c
void		ft_puttabnbr(int **tab, int len, int width);
// put_in_map.c
int			*parse_line(char *str, int width);
int			ft_tablen(char **tab);
int			ft_foundwidth(char *str);
void		put_in_map(s_env *stock);
//window.c
int			key_h(int keycode, void *stock);
void		ft_setwin(s_env *stock);

// draw.c
void		put_pixel_in_image(int x, int y, s_env *stock);
void		seg_trace(int *a, int *b, s_env *stock);

// tab.c
void		ft_init_tab(s_env *stock);
void		ft_free_tab(int ***tab, s_env *stock);

#endif
