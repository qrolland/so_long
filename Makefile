# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 18:36:28 by qrolland          #+#    #+#              #
#    Updated: 2023/01/19 17:57:08 by qrolland         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRCS		=	so_long.c \
			check_map.c \
			check_path.c \
			create_map.c \
			utils.c \
			read_key.c

OBJS			=	${addprefix srcs/,${SRCS:.c=.o}}

LD_FLAGS		=	-L libft -L mlx

MLX_FLAGS		=	-lm -lmlx -lXext -lX11

HEAD			=   -I include -I libft -I mlx

CC				=	gcc

CFLAGS			=	-Wall -Werror -Wextra

.c.o			:
					${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

$(NAME)			:	${OBJS}
					make -C libft
					make -C mlx
					${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS} -o ${NAME} -lft ${MLX_FLAGS}

all				:	${NAME}

clean			:
					make clean -C libft
					make clean -C mlx
					@rm -rf ${OBJS} ${OBJS_BONUS}

fclean			:	clean
					make fclean -C libft
					@rm -rf ${NAME}

re				:	fclean all