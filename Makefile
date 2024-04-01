CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c error.c check.c push_swap.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
       ft_lstmap.c ft_lstlast.c ft_lstnew.c some_func_list.c set_to_zero.c comands.c comands2.c comands3.c \
       algorithm2.c alg2_save.c some_func_list2.c some_func_list3.c ft_split.c ft_splitter.c\
	   alg3.c alg_send_to_b.c alg_output.c alg_find_best.c alg_send_to_a.c

NAME = push_swap

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f *.o

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re