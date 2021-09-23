# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 13:58:56 by cproesch          #+#    #+#              #
#    Updated: 2021/09/23 11:31:39 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c open_map.c check_map.c utils.c display_game.c \
			init_game.c key_events_utils.c

SRCS_B		= main.c open_map.c check_map.c utils.c key_events_utils.c \
			bonus/display_game_bonus.c bonus/init_game_bonus.c \
			bonus/utils_bonus.c

OBJS		= $(SRCS:.c=.o)

OBJS_B		= $(SRCS_B:.c=.o)

NAME		= so_long

CC			= clang

IFLAGS		= -I. -Ilibft -Imlx-linux

CFLAGS		= -Wall -Wextra -Werror $(IFLAGS)

LFLAGS		= -Llibft -Lmlx-linux -lft -lbsd -lXext -lX11 -lmlx-linux

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
