# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnathali <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/13 15:09:40 by mnathali          #+#    #+#              #
#    Updated: 2022/02/13 15:09:45 by mnathali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BON_NAME = checker

HEADER = push_swap.h

BON_HEADER = checker.h

LIB = libft/libft.a

SRC = another_calculations.c calculations.c create_stack.c\
	double_evaluations.c evaluations.c ft_criteria.c\
	ft_pa.c ft_sorting.c manage_errors.c push_swap.c\
	ra_rb_rr.c rra_rrb_rrr.c sa_sb_ss_pa_pb.c\
	recoursion.c recoursion_isolate.c

BON_SRC = create_stack.c ft_criteria.c manage_errors.c\
	checker.c get_next_line.c\
	ra_rb_rr.c rra_rrb_rrr.c sa_sb_ss_pa_pb.c

LIB_SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c\
	ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c\
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c\
	ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
	ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c\
	ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
	ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJSRC = $(patsubst %.c, %.o, $(SRC))

BON_OBJ = $(patsubst %.c, %.o, $(BON_SRC))

FLAGS = -Wall -Wextra -Werror

CC = cc

all: $(LIB) $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< 

$(SRC): $(HEADER)

$(LIB): $(patsubst ft_%.c, libft/ft_%.c, $(LIB_SRC)) libft/libft.h
	cd libft && $(MAKE)

$(NAME): $(OBJSRC) $(LIB)
	$(CC) $(FLAGS) $(OBJSRC) $(LIB) -o $@

clean:
	rm -rf $(OBJSRC) $(BON_OBJ)
	cd libft && $(MAKE) clean

fclean: clean
	rm -rf $(NAME) $(BON_NAME)
	cd libft && $(MAKE) fclean

re: fclean all

bonus: $(LIB) $(BON_NAME)

$(BON_SRC): $(BON_HEADER)

$(BON_NAME): $(BON_OBJ) $(LIB)
	$(CC) $(FLAGS) $(BON_OBJ) $(LIB) -o $@

.PHONY: all clean fclean bonus re 
