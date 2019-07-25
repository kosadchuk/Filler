# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 15:24:32 by kosadchu          #+#    #+#              #
#    Updated: 2019/04/10 12:28:33 by kosadchu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
INCLD :=	ft_printf.h

CC :=	clang
CFLAGS := -c -Wall -Wextra -Werror 

SRCS :=	ft_printf.c \
		format.c \
		chars.c \
		spec.c \
		decimal.c \
		ft_itoa_bs_pf.c \
		parsing.c \
		cast.c \
		float.c \
		float2.c \
		other_func.c \
		../ft_strchr.c \
		../ft_memalloc.c \
		../ft_strsub.c \
		../ft_strlen.c \
		../ft_atoi.c \
		../ft_bzero.c \
		../ft_lenint.c \
		../ft_strdup.c \
		../ft_strjoin.c

OBJ :=	ft_printf.o \
		format.o \
		chars.o \
		spec.o \
		decimal.o \
		ft_itoa_bs_pf.o \
		parsing.o \
		cast.o \
		float.o \
		float2.o \
		other_func.o \

 OBJS :=ft_strchr.o \
		ft_memalloc.o \
		ft_strsub.o \
		ft_strlen.o \
		ft_atoi.o \
		ft_bzero.o \
		ft_lenint.o \
		ft_strdup.o \
		ft_strjoin.o
#OBJ :=	$(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRCS) -I $(INCLD)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ) $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
