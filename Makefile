NAME = my_libc.a

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
 ar rcs $(NAME) $(OBJS)

%.o: %.c my_libc.h
 cc -Wall -Wextra -Werror -c $< -o $@

clean:
 rm -f $(OBJS)

fclean: clean
 rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
