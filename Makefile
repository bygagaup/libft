# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fschille <fschille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/27 16:59:39 by fschille          #+#    #+#              #
#    Updated: 2018/12/09 15:03:53 by fschille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = *.c

OBJ = *.o

INC = libft.h

all: $(NAME)


$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC) -I $(INC)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

mainre:
	rm -f main