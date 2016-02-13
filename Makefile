# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 15:48:47 by tbouder           #+#    #+#              #
#    Updated: 2016/01/05 10:37:06 by tbouder          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	alum1

CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra

SRC 		= 	ft_launcher.c ft_verifs.c ft_print_grid.c \
				ft_convert_as_int.c ft_game.c \
				ft_resolv_ia.c

LIB			=	libft.a

OBJ			=	$(SRC:.c=.o)

HEADER 		=	libft.h alum_one.h

all: $(NAME)

.SILENT : $(NAME)
$(NAME):
	# cd libft/ && $(MAKE) re
	$(CC) $(CFLAGS) -c $(HEADER) $(SRC)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

.SILENT : clean
clean:
	# cd libft/ && $(MAKE) clean
	rm -f $(OBJ)
	rm -f *.gch

.SILENT : fclean
fclean: clean
	# cd libft/ && $(MAKE) fclean
	rm -f $(NAME)

re: fclean all
