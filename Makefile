NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux

SRC = main.c fractol.c hooks.c init.c
OBJ = $(SRC:.c=.o)

MLX = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lbsd

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
