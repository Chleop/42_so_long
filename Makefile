# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 13:58:56 by cproesch          #+#    #+#              #
#    Updated: 2021/09/23 15:13:40 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= sources/main.c sources/open_map.c sources/check_map.c \
			sources/utils.c sources/display_game.c \
			sources/init_game.c sources/key_events_utils.c

SRCS_B		= sources/main.c sources/open_map.c sources/check_map.c \
			sources/utils.c sources/key_events_utils.c \
			bonus/display_game_bonus.c bonus/init_game_bonus.c \
			bonus/utils_bonus.c

OBJS		= $(SRCS:.c=.o)

OBJS_B		= $(SRCS_B:.c=.o)

NAME		= so_long

CC			= clang

IFLAGS		= -I. -Ilibft -Imlx-linux

CFLAGS		= -Wall -Wextra -Werror $(IFLAGS)

LFLAGS		= -Llibft -Lmlx-linux -lft -lbsd -lXext -lX11 -lmlx

RM			= rm -rf

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			make -C libft
			make -C mlx-linux
			$(CC) $(OBJS) $(LFLAGS) -o $(NAME)

all:		$(NAME)

clean:	
			make -C libft -f Makefile clean
			make -C mlx-linux -f Makefile clean
			$(RM) $(OBJS) $(OBJS_B)

fclean:		clean
			make -C libft -f Makefile fclean
			$(RM) $(NAME)

re:			fclean all

bonus:		$(OBJS_B)
			make -C libft
			make -C mlx-linux
			$(CC) $(OBJS_B) $(LFLAGS) -o so_long_bonus

.PHONY:		all clean fclean re
