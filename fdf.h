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
	char		*file;
}			t_env;

void		ft_error(char *str);
void		open_and_init(char *file, int argc, s_env *stock);

#endif
