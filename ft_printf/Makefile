# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytsyrend <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 21:47:29 by ytsyrend          #+#    #+#              #
#    Updated: 2023/09/05 21:47:32 by ytsyrend         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	=	libftprintf.a

SRC		=	ft_make_hexa.c \
			ft_printf.c\
			ft_printnmb.c\
			ft_putchar.c\
			ft_putstr.c\
			ft_putstr_fd.c\
			ft_strchr.c\
			ft_strlen.c\

OBJ		=	${SRC:.c=.o}

CC		=	cc
RM		=	rm -f
AR		=	ar rc
RN		=	ranlib

CFLAGS	=	-Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME):	${OBJ} 
	@echo "Compiling and creating .o .a files .."
	${AR} ${NAME} ${OBJ}
	${RN} ${NAME}
	@echo "Done!"

clean:
	@echo "Remove .o files  ..."
	${RM} ${OBJ}
	@echo "Done!"

fclean: clean
	@echo "Remove lib ..."
	${RM} $(NAME)
	@echo "Done!"

re: fclean all  