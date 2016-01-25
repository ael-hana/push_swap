NAME=push_swap

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

SRC=ft_action.c \
	ft_action_p.c \
	ft_action_r.c \
	ft_action_rr.c \
	ft_algo_bf.c \
	ft_algo_s.c \
	ft_check_params.c \
	ft_push_swap.c

OBJ=$(SRC:.c=.o)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(OBJ) -o $(NAME) -L. -lft

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean
