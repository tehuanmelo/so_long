NAME = libftprintf.a
SRC = ft_printf.c ft_putchar.c ft_puthex.c ft_putnbr.c ft_putstr.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

.SILENT:

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)


all: $(NAME)

clean:
		rm -f *.out *.o

fclean: clean	
		rm -f *.a

re: fclean all