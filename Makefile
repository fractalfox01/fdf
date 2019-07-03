NAME= fdf

FLAGS= -Wall -Werror -Wextra

LIBS= -Lsrc/libft -lft -Lminilibx -lmlx

#MLX= -Lmlx/ -lmlx

x86= -Lminilibx/ -lmlx_x86_64

INT= -Lminilibx/ -lmlx_intel-mac

MLX= -Lminilibx -Iminilibx -lmlx -framework OpenGL -framework AppKit

MACOS= -Lminilibx_macos/ -Iminilibx_macos/ -lmlx

FRAMEWORK= -framework OpenGL -framework AppKit

DEBUG= -g

all: $(NAME)

SRC= $(addprefix src/, main.c fdf.c print_util.c read_util.c free_utils.c draw_utils.c)

MLXSRC= $(addprefix minilibx/, mlx_clear_window.c mlx_get_data_addr.c \
	mlx_int_param_event.c mlx_loop.c mlx_put_image_to_window.c mlx_destroy_image.c \
	mlx_hook.c mlx_int_set_win_event_mask.c mlx_loop_hook.c mlx_rgb.c \
	mlx_destroy_window.c mlx_init.c mlx_int_str_to_wordtab.c mlx_mouse_hook.c \
	mlx_string_put.c mlx_expose_hook.c mlx_int_anti_resize_win.c \
	mlx_int_wait_first_expose.c mlx_new_image.c mlx_xpm.c mlx_flush_event.c \
	mlx_int_do_nothing.c mlx_key_hook.c mlx_new_window.c mlx_get_color_value.c \
	mlx_int_get_visual.c mlx_lib_xpm.c mlx_pixel_put.c)

LIBFT= -Isrc/libft/ -Lsrc/libft/ -lft

GREEN= '\033[0;31'

$(NAME):
	@printf "Building...\n"
	@make -C minilibx
	@echo "\033[0;33m"
	@make -C src/libft
	#gcc -g -I -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit -L $(LIB) -lft make
	@$(CC) -g $(MACOS) $(MLX) $(LIBFT) $(SRC) -o fdf

clean:
	@echo "\033[d"
	@echo "\033[0;32mCleaning Up..."
	make -C src/libft clean

fc: fclean

fclean: clean
	@if [ -a fdf.dSYM ] ; then \
		echo "\033[0;32mRemoving fdf.dSYM"; \
		rm -rf fdf.dSYM; \
	fi
	@if [ -a $(NAME) ] ; then \
		echo "\033[0;32mRemoving $(NAME)"; \
		rm $(NAME); \
	else \
		echo "\033[0;32m$(NAME) already removed"; \
	fi
	make -C src/libft fclean

re: fc all

.PHONY: $(NAME)
