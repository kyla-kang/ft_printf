NAME = libftprintf.a

SRCS =	ft_printf.c

OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):$(OBJS)
	ar -cr $(NAME) $(OBJS)

%.o:%.c ft_printf.h
	cc $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJS)

fclean:clean
	rm -rf $(NAME)

re: fclean all
#NAME 		= libftprintf.a
#SOURCES = ft_atoi.c process_specifier.c ft_printf.c print_char.c print_dec.c print_hexa.c print_ptr.c print_str.c
#OBJECTS = $(SOURCE:.c=.o)

#CC = cc
#CFLAGS = -Wall -Wextra -Werror

#all: $(NAME)

#bonus: all

#$(NAME): $(OBJECTS)
#	$(AR) -r $(NAME) $(OBJECTS)

#%.o: %.c
#	$(CC) $(CFLAGS) $?

#clean:
#	rm -f $(OBJECTS)

#fclean: clean
#	rm -f $(NAME)

#re: fclean all

#.PHONY: all clean fclean re bonus
