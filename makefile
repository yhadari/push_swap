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

NAME = push_swap

$(NAME) : all

all :
	@gcc -g -Wall -Wextra -Werror $(FT) -o $(NAME)

fclean :
	@rm -f $(NAME)

re : fclean all