NAME = libftprintf.a
SOURCES = main.c ft_atoi.c ft_printf.c init_flag.c print_char.c print_str.c print_dec.c print_hexa.c print_ptr.c process.c process_flag.c process_number.c process_precision.c
OBJECTS = $(SOURCE:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus: all

$(NAME): $(OBJECTS)
	$(AR) -r $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) $??

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
