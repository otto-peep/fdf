#include "fdf.h"

int		main(int argc, char **argv)
{
	s_env	*stock;

	stock = (s_env*) malloc (sizeof(s_env));
	open_and_init(argv[1], argc, stock);
	ft_putstr(stock->file);
	return (0);
}
	
