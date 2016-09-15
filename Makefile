NAME = fdf

HEAD = ./include/

PATH_LIB = ./libft/

PATHSRC = ./src/

FLAGS = -Wall -Wextra -Werror

FILES = main.c		\
	error.c			\
	file.c			\
	put_in_map.c	\
	tools.c			\
	window.c		\
	draw.c			\
	tab.c			\
	function.c		\
	rot.c

SRC = $(FILES:%c=$(PATHSRC)%c)

STATICPATH = -lm -L libft/ -lft -L./minilibx_macos -I./minilibx_macos -lmlx -framework OpenGL -framework AppKit

MLXPATH = -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

OBJ = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME):
	make -C libft/
	gcc $(FLAGS) -o $(NAME) $(SRC) -I $(HEAD) $(STATICPATH)

clean :
	make -C libft/ clean

fclean :
	make -C libft/ fclean
	rm -f $(NAME)

re : fclean all
