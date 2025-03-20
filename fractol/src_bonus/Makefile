NAME = ../fractol
SRC = events_bonus.c fractol_bonus.c fractol_utils_bonus.c render_bonus.c burnship_bonus.c fractol_utils2_bonus.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -L../mlx -lmlx -framework OpenGL -framework AppKit
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(MLX) $(OBJ) -o $(NAME)
%.o: %.c fractol_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean