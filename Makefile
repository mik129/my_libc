NAME = my_libc.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -std=c11

SRCS = my_strlen.c \
       my_strcpy.c \
       my_strncpy.c \
       my_strcat.c \
       my_strncat.c \
       my_strcmp.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
