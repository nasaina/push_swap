NAME = push_swap

CFLAGS = -Wall -Werror -Wextra -g

CC = cc

INCLUDES = -I includes/

SRC =	./src/main.c ./src/swap.c ./src/error.c ./src/list.c \
		./src/free.c ./src/sorting.c ./src/ft_atol.c ./src/detach.c \
		./src/reverse_rotate.c ./src/rotate.c ./src/push.c \
		./src/check_sort.c ./src/math.c ./src/sort_max.c \
		./src/get_target.c ./src/check_move.c ./src/push_b.c \
		./src/push_a.c \

LIBFT = ./libft/libft.a

FT_PRINTF = ./libft/ft_printf/libftprintf.a

LIBFT =  ./libft/libft.a

OBJ = $(SRC:%.o=%.c)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C ./libft
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INCLUDES) $(LIBFT) $(FT_PRINTF)
	@clear
	@echo "\n\e[1;91mExecute the program with \e[0m./push_swap int int...\n"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $

clean_libft :
	@make clean -C libft

fclean_libft :
	@make fclean -C libft

clean : clean_libft
	@rm -rf *.o
	@clear

fclean : clean fclean_libft
	@rm -rf push_swap
	@clear

re : fclean all

.PHONY : all clean fclean re