/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:08:13 by user42            #+#    #+#             */
/*   Updated: 2021/09/21 14:40:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <X11/keysym.h>

# define PIC_BACK "./images/back.xpm"
# define PIC_WALL "./images/wall.xpm"
# define PIC_EXIT "./images/exit.xpm"
# define PIC_COLL "./images/coll.xpm"
# define PIC_PLAYER "./images/player.xpm"
# define PIC_MOUV "./images/mouv.xpm"

enum e_enum
{
	ESC = 65307,
	W = 119,
	A = 97,
	S = 115,
	D = 100
};

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map_tab;
	size_t	map_width;
	size_t	map_length;
	int		player_x;
	int		player_y;
	int		nb_c;
	int		nb_e;
	int		nb_p;
	void	*pic_back;
	void	*pic_wall;
	void	*pic_exit;
	void	*pic_coll;
	void	*pic_player;
	void	*pic_mouv;
	int		pic_width;
	int		pic_height;
	int		mouv;
}	t_data;

void	init_variables(t_data *data);
void	open_map(char *map_address, t_data *data);
void	check_map(t_data *data);
void	error_message(char *str, t_data *data);
void	del(char **str);
void	display_game(t_data data);
void	init_game(t_data *data);
void	ft_exit(t_data *data, int extype);
void	is_collected(char next_p, t_data *data);
void	mouvement(char next_p, int keypress, t_data *data);
int		is_exit(char next_p, t_data *data);
char	*print_mvmts(t_data *data);
void	make_mouv(char next_p, int keypress, t_data *data);
char	set_next_p(int keypress, t_data *data);

#endif
