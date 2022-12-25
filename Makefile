NAME = so_long
SRC = $(wildcard ./*c)
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# PATHS
LIBFT = ./libft
FT_PRINTF = ./ft_printf
MLX = ./mlx

.SILENT:

$(NAME):	$(OBJ)
	cd $(FT_PRINTF) && $(MAKE)
	cd $(LIBFT) && $(MAKE)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a $(MLX)/libmlx.a -framework OpenGL -framework AppKit -o $@
	echo "Compilation done successfully!"
	echo "Execute ./so_long file.ber"

all:	$(NAME)

clean:
	 rm -f *.o *.out
	 cd $(LIBFT) && $(MAKE) clean
	 cd $(FT_PRINTF) && $(MAKE) clean

fclean:	clean
	 rm -f *.av $(NAME)
	 cd $(LIBFT) && $(MAKE) fclean
	 cd $(FT_PRINTF) && $(MAKE) fclean

re:	fclean all

