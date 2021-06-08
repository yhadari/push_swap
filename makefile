# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhadari <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 16:47:09 by yhadari           #+#    #+#              #
#    Updated: 2021/05/28 16:47:10 by yhadari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT = pushswap.c push.c swap.c stack.c rotate.c reverse.c sort.c pushatob.c \
	ifisorted.c randomsort.c pushbtoa.c chunkmetod.c isinchunk.c checkstackb.c \
	lib.c
FB = checker.c lib.c push.c swap.c rotate.c reverse.c stack.c ifisorted.c \
	get_next_line.c

NAME = push_swap
checker = checker

all : $(NAME)

$(NAME) :
	@gcc -g -Wall -Wextra -Werror $(FT) -o $(NAME)
	@gcc -g -Wall -Wextra -Werror $(FB) -o $(checker)

clean :
	@rm  -f *.o

fclean : clean
	@rm -f $(NAME)
	@rm -f $(checker)

re : fclean all