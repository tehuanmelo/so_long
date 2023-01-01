NAME = so_long
SRCPATH = ./src/
SRCFILES = check_player_position.c create_image.c draw_image.c draw_map.c end_game.c initialize_game.c initialize_game_utils.c player_moves.c so_long.c validate_map.c validate_map_elements.c validate_map_structure.c 
SRC = $(foreach FILE,$(SRCFILES),./src/$(FILE))
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3

# PATHS
LIBFT = ./inc/libft
FT_PRINTF = ./inc/ft_printf
MLX = ./inc/mlx

.SILENT:

$(NAME):	$(OBJ)
	cd $(FT_PRINTF) && $(MAKE)
	cd $(LIBFT) && $(MAKE)
	cd $(MLX) && $(MAKE)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a $(MLX)/libmlx.a -framework OpenGL -framework AppKit -o $@
	echo "Compilation done successfully!"
	echo "Execute ./so_long file.ber"

all:	$(NAME)

clean:
	 rm -f ./src/*.o ./src/*.out
	 cd $(LIBFT) && $(MAKE) clean
	 cd $(MLX) && $(MAKE) clean
	 cd $(FT_PRINTF) && $(MAKE) clean

fclean:	clean
	 rm -f $(NAME)
	 cd $(LIBFT) && $(MAKE) fclean
	 cd $(FT_PRINTF) && $(MAKE) fclean

re:	fclean all

