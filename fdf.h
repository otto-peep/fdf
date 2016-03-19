/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:32:09 by pconin            #+#    #+#             */
/*   Updated: 2016/03/19 17:42:03 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
#define ESC 12
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
{
	int			width;
	int			len;
	int			**map;
	char		*file;
}			t_env;

int			ft_tablen(char **tab);
void		ft_error(char *str);
void		open_and_init(char *file, int argc, s_env *stock);
void		put_in_map(s_env *stock);

#endif
