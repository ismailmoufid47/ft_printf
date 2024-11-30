NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ = ft_printf.o putstr.o putnbr.o puthex.o putptr.o putnbru.o

$(NAME): $(OBJ) ft_printf.h
	ar rc $(NAME) $(OBJ)

all: $(NAME)

bonus:	all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all