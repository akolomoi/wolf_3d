NAME = wolf3d

SRCNAME =	create_window.c \
			events.c \
			map.c \
			errors.c \
			wolf_3d.c

SRC = $(addprefix src/, $(SRCNAME))
OBJ = $(SRC:.c=.o)
FLAGS = -l mlx -framework OpenGL -framework AppKit
HDIR = includes
LFT = libft/libft.a

.SILENT:

all : $(NAME)

$(NAME): lib $(OBJ)
	gcc -g $(OBJ) $(LFT) $(FLAGS) -o $(NAME)
	@echo "(*) wolf3d"

%.o: %.c
	gcc -o $@ -c $< -I include
	@echo "(+) $@"

lib :
	make -C libft

clean:
	rm -f $(OBJ)
	make clean -C libft
	@echo "(-) *.o"

fclean: clean
	make fclean -C libft
	rm -f $(NAME)
	@echo "(-) libft"
	@echo "(-) wolf3d"

re: fclean all
