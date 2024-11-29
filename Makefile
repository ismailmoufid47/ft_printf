NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ = ft_printf.o putchar.o putstr.o putnbr.o
$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

all: $(NAME)

bonus:	all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all