
NAME = push_swap

SRCS = check_sort.c free.c main.c parsing.c push_swap.c rotate.c utilis.c utilis_1.c sort_3num.c ft_split.c sort_5num.c sort_num.c get_index.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -fsanitize=address

%.o: %.c ./include/push_swap.h
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
