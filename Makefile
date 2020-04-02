# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijang <ijang@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/01 15:57:34 by ijang             #+#    #+#              #
#    Updated: 2020/04/02 21:28:32 by ijang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_SRCS =		./

SRCS =			${PATH_SRCS}factorization.c		\
				${PATH_SRCS}ft_initialize.c		\
				${PATH_SRCS}ft_atoi_mk2.c		\
				${PATH_SRCS}ft_printerror.c

OBJS =			${SRCS:.c=.o}

INCS =			./

NAME =			factorization

CC =			gcc

RM =			rm -f

CFLAGS =		-Wall -Wextra -Werror

%.o: %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}
	
${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all : ${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all
