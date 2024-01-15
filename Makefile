CC = cc
CFLAGS = -g -Wall -Wextra -Werror
RM = rm -rf
NAME = push_swap
LIBFT = ./libft/libft.a
SRC_1 = src/push_swap.c
SRC_2 = src/error.c \
		src/ft_free.c \
		src/init_stack_a.c \
		src/lst_utils.c \
		src/operations_1.c \
		src/operations_2.c \
		src/push_a_to_b.c \
		src/set_and_push_b_to_a.c \
		src/set_nodes_a_to_b.c \
		src/sort_list.c \
		src/sort_three_nb.c

OBJ_1 = $(SRC_1:.c=.o)
OBJ_2 = $(SRC_2:.c=.o)


all: $(NAME)

$(LIBFT):
	@make -C ./libft

$(NAME): $(OBJ_1) $(OBJ_2) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_1) $(OBJ_2) $(LIBFT) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_1) $(OBJ_2)
	@make clean -C ./libft

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)

re: fclean all