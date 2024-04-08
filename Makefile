# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/17 11:35:05 by gkoechli          #+#    #+#              #
#    Updated: 2021/10/27 18:07:46 by gkoechli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
OBJS = ${SRC:.c=.o}
FLAGS = -Wall -Werror -Wextra
SRC = srcs/ft_printf.c	\
	  srcs/utils.c	\
	  srcs/tools.c	\
	  srcs/tools_2.c	\
	  srcs/flags.c	\
	  srcs/baseconv.c	\
	  srcs/convert.c
$(NAME): ${OBJS}
	ar -rcs ${NAME} ${OBJS}
bonus: ${NAME} 
.c.o:
	gcc ${FLAGS} -c $< -o ${<:.c=.o}
all: ${NAME}
clean:
	rm -f ${OBJS}
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re bonus
