# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/13 20:52:37 by wpersimm          #+#    #+#              #
#    Updated: 2021/07/13 15:33:25 by wpersimm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/ft_swap.c\
			srcs/less_then_six.c\
			srcs/main.c\
			srcs/pa.c\
			srcs/ra.c\
			srcs/rr.c\
			srcs/rra.c\
			srcs/rrr.c\
			srcs/sa.c\
			srcs/sort_hundred.c\
			srcs/sort_hundred_2.c\
			srcs/utils.c

SRCC	=	srcs/ft_swap.c\
			srcs/pa.c\
			srcs/ra.c\
			srcs/rra.c\
			srcs/sa.c\
			srcs/utils.c\
			check/checker.c

SRCSB	=	bonus/checker.c\
			bonus/draw_bonus.c\
			srcs/ft_swap.c\
			srcs/pa.c\
			srcs/ra.c\
			srcs/rra.c\
			srcs/sa.c\
			srcs/utils.c

SRCL	=	libft/ft_atoi.c\
			libft/ft_bzero.c\
			libft/ft_calloc.c\
			libft/ft_isalnum.c\
			libft/ft_isalpha.c\
			libft/ft_isascii.c\
			libft/ft_isdigit.c\
			libft/ft_isprint.c\
			libft/ft_itoa.c\
			libft/ft_lstadd_back.c\
			libft/ft_lstadd_front.c\
			libft/ft_lstclear.c\
			libft/ft_lstdelone.c\
			libft/ft_lstiter.c\
			libft/ft_lstlast.c\
			libft/ft_lstmap.c\
			libft/ft_lstnew.c\
			libft/ft_lstsize.c\
			libft/ft_memccpy.c\
			libft/ft_memchr.c\
			libft/ft_memcmp.c\
			libft/ft_memcpy.c\
			libft/ft_memmove.c\
			libft/ft_memset.c\
			libft/ft_putchar_fd.c\
			libft/ft_putendl_fd.c\
			libft/ft_putnbr_fd.c\
			libft/ft_putstr_fd.c\
			libft/ft_split.c\
			libft/ft_strchr.c\
			libft/ft_strdup.c\
			libft/ft_strjoin.c\
			libft/ft_strlcat.c\
			libft/ft_strlcpy.c\
			libft/ft_strlen.c\
			libft/ft_strmapi.c\
			libft/ft_strncmp.c\
			libft/ft_strnstr.c\
			libft/ft_strrchr.c\
			libft/ft_strtrim.c\
			libft/ft_substr.c\
			libft/ft_tolower.c\
			libft/ft_toupper.c\
			libft/get_next_line.c\
			libft/get_next_line_utils.c

LIBO	=	${SRCL:.c=.o}

LIBH	=	libft/libft.h

HEAD	=	includes/push_swap.h

NAME	=	push_swap

CHECK	=	checker

BONUS	=	checker_bonus

LIBA	=	libft/libft.a

MLX		=	mlx/libmlx.a

BFLAGS	=	-Wall -Wextra -Werror -Ilibft -lft -Llibft -Iincludes -Lmlx -lmlx -Imlx -framework OpenGL -framework Appkit

FLAGS	=	-Wall -Wextra -Werror -Ilibft -lft -Llibft -Iincludes

all:	${NAME} ${CHECK}

bonus:	${BONUS}

${NAME}:	${HEAD} ${SRCS} ${LIBA}
			gcc ${FLAGS} ${SRCS} -o ${NAME}

${CHECK}:	${HEAD} ${SRCC} ${LIBA}
			gcc ${FLAGS} ${SRCC} -o ${CHECK}

${BONUS}:	${HEAD} ${SRCSB} ${LIBA} ${MLX}
			gcc ${BFLAGS} ${SRCSB} -o ${BONUS}

${LIBA}:	${LIBO} ${LIBH}
			make -C libft

${MLX}:
			make -C mlx

clean:
		make fclean -C libft
		make clean -C mlx

fclean: clean
		rm -rf ${NAME}
		rm -rf ${CHECK}
		rm -rf ${BONUS}

re:		fclean all


