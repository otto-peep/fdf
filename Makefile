NAME = mlx

HEAD = ./fdf.h

PATH_LIB = ./libft/

FLAGS = -Wall -Wextra -Werror

SRC = test.c

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	make -C libft/
	gcc -o $(NAME) $(SRC) -L./minilibx_macos -I./minilibx_macos -lmlx -framework OpenGL -framework AppKit

.PHONY : clean fclean re all

clean :
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean :
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re :
	fclean all
	
