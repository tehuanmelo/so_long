NAME = libftprintf.a
SRC = $(wildcard ./*c)
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
		ar r $(NAME) $(OBJ)
.SILENT:

all: $(NAME)

clean:
		rm -f *.out *.o

fclean: clean	
		rm -f *.a

re: fclean all