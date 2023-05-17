# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cleblais <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 09:27:05 by cleblais          #+#    #+#              #
#    Updated: 2022/12/08 14:15:54 by cleblais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		push_swap

SRCS		=		ps_big.c ps_medium.c ps_mvts_pr.c ps_mvts_s.c ps_utils.c\
					push_swap.c

OBJS		= 		$(SRCS:.c=.o)

CC			=		gcc

LIB			= 		libft/libft.a ft_printf/libftprintf.a
	
CFLAGS		=		-Wall -Wextra -Werror -g

RM			= 		rm -f

all			:		$(NAME)

$(NAME)		:		$(OBJS) $(LIB)
					$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

$(LIB)		:
					make -C libft
					make clean -C libft
					make -C ft_printf
					make clean -C ft_printf

clean		:
					$(RM) $(OBJS)

fclean		:		clean
					$(RM) $(NAME)

re			:		fclean all
