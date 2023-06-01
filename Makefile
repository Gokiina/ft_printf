# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anarodr2 <anarodr2@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 12:05:39 by anarodr2          #+#    #+#              #
#    Updated: 2023/03/23 12:36:30 by anarodr2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wextra -Werror -Wall

SRC = ft_printf.c ft_ptr.c ft_numbers.c ft_letters.c

INCLUDE = ./ft_printf.h
LIB = ar -rcs 
OBJ = $(SRC:.c=.o) 
RM = rm -fr

all: $(MAKE) $(NAME)

%.o: %.c ${INCLUDE}
	$(CC) $(CFLAGS) -I${INCLUDE} -c $< -o $@

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re
