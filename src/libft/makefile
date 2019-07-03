NAME= libft.a

FLAGS= -Wall -Wextra -Werror

SRC := $(addsuffix .c, get_n_char ft_hex_to_int ft_strsplit_int ft_isspace sort_list_bubble ft_get_lst_len get_n_char get_next_line ft_abs ft_strpbrk ft_iscntrl ft_isgraph ft_realloc sort_selection sort_bubble ft_lstmap ft_lstadd ft_lstiter ft_lstdel sort_bubble ft_lstdelone ft_lstnew ft_strbuild ft_power ft_putnbr_fd ft_putendl_fd ft_putstr_fd ft_putchar_fd ft_putendl ft_itoa ft_strxlen ft_wordcount ft_strsplit ft_whitespace ft_strtrim ft_strjoin ft_strsub ft_strnequ ft_strequ ft_strmapi ft_strmap ft_striteri ft_striter ft_strclr ft_strdel ft_strnew ft_memdel ft_memalloc ft_strnlen ft_strnstr ft_strlcat ft_strncat ft_strncpy ft_atoi ft_isascii ft_memchr ft_memset ft_strcat ft_strdup ft_strrchr ft_bzero ft_isdigit ft_memcmp ft_putchar ft_strchr ft_strlcat ft_strstr ft_isalnum ft_isprint ft_memcpy ft_putnbr ft_strcmp ft_strlen ft_tolower ft_isalpha ft_memccpy ft_memmove ft_putstr ft_strcpy ft_strncmp ft_toupper)

OBJ := $(addsuffix .o, get_n_char ft_hex_to_int ft_strsplit_int ft_isspace sort_list_bubble ft_get_lst_len get_n_char get_next_line ft_abs ft_strpbrk ft_iscntrl ft_isgraph ft_realloc sort_selection ft_lstmap ft_lstadd ft_lstiter ft_lstdel sort_bubble ft_lstdelone ft_lstnew ft_strbuild ft_power ft_putnbr_fd ft_putendl_fd ft_putstr_fd ft_putchar_fd ft_putendl ft_itoa ft_strxlen ft_wordcount ft_strsplit ft_whitespace ft_strtrim ft_strjoin ft_strsub ft_strnequ ft_strequ ft_strmapi ft_strmap ft_striteri ft_striter ft_strclr ft_strdel ft_strnew ft_memdel ft_memalloc ft_strnlen ft_strnstr ft_strncat ft_strncpy ft_atoi ft_isascii ft_memchr ft_memset ft_strcat ft_strdup ft_strrchr ft_bzero ft_isdigit ft_memcmp ft_putchar ft_strchr ft_strlcat ft_strstr ft_isalnum ft_isprint ft_memcpy ft_putnbr ft_strcmp ft_strlen ft_tolower ft_isalpha ft_memccpy ft_memmove ft_putstr ft_strcpy ft_strncmp ft_toupper)

$(NAME):
	@echo "\033[1;32mBuilding Libft..."
	@gcc -c $(FLAGS) $(SRC)
	@ar rc libft.a $(OBJ)

all: $(NAME)

clean: 
	@echo "\033[1;36mCleaning Up Library, removing all object files.\033[0;31m"
	@for f in $(OBJ) ; do \
		rm $$f 2>/dev/null && echo "\033[0;36mSuccessfully Removed $$f" || echo ""; \
	done

fclean: clean
	@echo "\033[1;32mremoving libft.a"
	@rm libft.a 2>/dev/null || echo "You've Already Removed libft.a"

fc: fclean

re: fclean all

test_start: $(NAME) clean
	gcc -g -Wall -Werror -Wextra main.c -L. -lft -o temp_testing

test_rm: fc
	rm temp_testing
	rm -rf temp_testing.dSYM

test_re: test_rm test_start

test_hide:
	mv main.c main.txt

test_unhide:
	mv main.txt main.c

.PHONY: fclean testall libft all clean
