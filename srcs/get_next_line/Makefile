NAME	:= getnextline.a
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -I.

FILES	:= $(wildcard *.c)
OBJS	:= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)


clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
