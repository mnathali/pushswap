NAME = push_swap

BON_NAME = checker

SRC = 

OBJSRC = $(patsubst %.c, %.o, $(SRC))

FLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

$(HEADERLIB): libft.h

%.o : %.c
	$(CC) $(FLAGS) -c $<

$(NAME): $(LIBSRC) $(HEADERLIB)
	ar rcs $(NAME) $?

clean:
	rm -rf $(LIBSRC) $(BONUSLIB)

fclean: clean
	rm -rf $(NAME)

re: fclean all

bonus:


.PHONY: all clean fclean re 