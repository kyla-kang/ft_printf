
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =	ft_printf.c ft_putchar.c ft_puthex.c ft_putnbr.c ft_putptr.c ft_putstr.c ft_putunbr.c handle_conversion.c init_format.c parse_width_precision.c set_flag.c
BONUS_SRCS = ft_printf.c ft_putchar.c ft_puthex.c ft_putnbr.c ft_putptr.c ft_putstr.c ft_putunbr.c handle_conversion.c init_format.c parse_width_precision.c set_flag.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
TEST_SRCS = main.c
TEST_OBJS = $(TEST_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)

test: $(NAME) $(TEST_OBJS)
	$(CC) $(CFLAGS) -o test $(TEST_OBJS) $(NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS) $(TEST_OBJS)

fclean: clean
	rm -f $(NAME) test

re: fclean all

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: all clean fclean re bonus test
