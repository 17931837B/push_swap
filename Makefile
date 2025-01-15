SRCS = calculate_distance.c check_input.c choice_move.c compression.c \
       count_size.c error.c free_stack.c ft_atoi.c \
       ft_isdigit.c ft_split.c ft_strjoin.c get_stack.c \
       last_arrange.c main.c push.c rotate.c \
       rrotate.c search_target_pos.c select_way.c set_stack.c \
       shortest_move.c sort_four.c sort_other.c sort_over_500.c \
       sort_three.c swap.c

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
