
NAME = push_swap

SRCS = ps/check_sort.c ps/free.c ps/main.c ps/parsing.c ps/push_swap.c ps/rotate.c ps/utilis.c ps/utilis_1.c ps/sort_3num.c ps/ft_split.c ps/sort_5num.c ps/sort_num.c ps/get_index.c
B_SRCS = bonus/checker.c bonus/get_next_line.c bonus/push_swap.c bonus/rotate.c bonus/utilis.c bonus/utilis_1.c bonus/parsing.c bonus/ft_split.c

OBJS = $(SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)

HEADER = ps/push_swap.h
B_HEADER = bonus/push_swap.h

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

all: $(NAME)

bonus : checker

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

checker: $(B_OBJS)
	$(CC) $(CFLAGS) $(B_OBJS) -o checker

ps/%.o: ps/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c $(B_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	$(RM) $(NAME) checker

re: fclean all bonus
