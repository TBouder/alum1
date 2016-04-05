# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 15:48:47 by tbouder           #+#    #+#              #
#    Updated: 2016/04/05 20:21:26 by tbouder          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	alum1

CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra

SRC 		= 	ft_launcher.c ft_verifs.c ft_print_grid.c \
				ft_convert_as_int.c ft_game.c \
				ft_resolv_ia.c

LIB			=	libft/libft.a

OBJ			=	$(SRC:.c=.o)

HEADER 		=	libft/libft.h alum_one.h

all: $(NAME)

.SILENT : $(NAME)
$(NAME):
	$(MAKE) re -C libft
	$(CC) $(CFLAGS) -c $(HEADER) $(SRC)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

.SILENT : clean
clean:
	$(MAKE) clean -C libft
	rm -f $(OBJ)
	rm -f *.gch

.SILENT : fclean
fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)

re: fclean all
