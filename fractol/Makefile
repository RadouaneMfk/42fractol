NAME = fractol
SRC = src/fractol.c src/fractol_utils.c src/events.c src/render.c src/fractol_utils2.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(MLX) $(OBJ) -o $(NAME)
%.o: %.c src/fractol.h
	$(CC) $(CFLAGS) -c $< -o $@
bonus:
	@make all -C src_bonus
clean:
	rm -f $(OBJ)
	make clean -C src_bonus

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean