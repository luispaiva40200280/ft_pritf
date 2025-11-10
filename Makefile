# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaiva <lpaiva@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/07 21:53:12 by lpaiva            #+#    #+#              #
#    Updated: 2025/11/10 19:04:25 by lpaiva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c ft_utilites.c ft_utilities_hex_uns.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	
clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME) printf_tests

re: fclean all

.PHONY: all clean fclean re start end party

##	./printf_tests
##test: $(NAME)
##	$(CC) printf_tests.c -L. -lftprintf -o printf_tests
