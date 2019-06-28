NAME= fdf

FLAGS= -Wall -Werror -Wextra

LIBS= -Lsrc/libft -lft -Lminilibx -lmlx

#MLX= -Lmlx/ -lmlx

x86= -Lminilibx/ -lmlx_x86_64

INT= -Lminilibx/ -lmlx_intel-mac

MLX= -L minilibx -lmlx -framework OpenGL -framework AppKit

FRAMEWORK= -framework OpenGL -framework AppKit

DEBUG= -g

all: $(NAME)

SRC= $(addprefix src/, main.c ft_fdf.c fdf_console_log.c read_utils.c draw.c point_utils.c rotate_utils.c)

MLXSRC= $(addprefix minilibx/, mlx_clear_window.c mlx_get_data_addr.c \
	mlx_int_param_event.c mlx_loop.c mlx_put_image_to_window.c mlx_destroy_image.c \
	mlx_hook.c mlx_int_set_win_event_mask.c mlx_loop_hook.c mlx_rgb.c \
	mlx_destroy_window.c mlx_init.c mlx_int_str_to_wordtab.c mlx_mouse_hook.c \
	mlx_string_put.c mlx_expose_hook.c mlx_int_anti_resize_win.c \
	mlx_int_wait_first_expose.c mlx_new_image.c mlx_xpm.c mlx_flush_event.c \
	mlx_int_do_nothing.c mlx_key_hook.c mlx_new_window.c mlx_get_color_value.c \
	mlx_int_get_visual.c mlx_lib_xpm.c mlx_pixel_put.c)

LIBFT= $(addprefix src/libft/, get_n_char.c ft_isdigit.c ft_abs.c ft_strcpy.c ft_strsplit_int.c ft_atoi.c ft_putnbr.c ft_strclr.c ft_memcpy.c ft_strncpy.c ft_strxlen.c ft_wordcount.c ft_strsplit.c ft_strbuild.c ft_putchar.c ft_putstr.c ft_strdup.c ft_strlen.c ft_strdel.c ft_strnew.c get_next_line.c ft_bzero.c ft_memalloc.c ft_memdel.c ft_memset.c ft_strchr.c ft_strjoin.c)

GREEN= '\033[0;31'

$(NAME):
	@printf "Building...\n"
	@make -C minilibx
	@echo "\033[0;33m"
	@make -C src/libft
	#gcc -g -I -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit -L $(LIB) -lft make
	@$(CC) -g -Iminilibx_macos/ -Lminilibx_macos/ -lmlx $(MLX) $(LIBFT) $(SRC) -o fdf

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
