NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC_DIR = includes

SOURCES = main.c ft_atoi.c ft_printf.c init_flag.c print_char.c print_str.c print_dec.c print_hexa.c print_ptr.c process.c process_flag.c process_number.c process_precision.c
OBJECTS = $(SOURCE:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

bonus: all

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
