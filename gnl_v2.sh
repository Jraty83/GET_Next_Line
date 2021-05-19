make -C libft/ fclean && make -C libft/
clang -Wall -Wextra -Werror -I libft/includes -o get_next_line_v2.o -c get_next_line_v2.c
clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
clang -o test_gnl main.o get_next_line_v2.o -I libft/includes -L libft/ -lft
