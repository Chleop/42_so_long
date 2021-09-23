/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 20:04:59 by user42            #+#    #+#             */
/*   Updated: 2021/09/21 11:04:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_collected(char next_p, t_data *data)
{
	if (next_p == 'C')
		data->nb_c = data->nb_c - 1;
}

void	mouvement(char next_p, int keypress, t_data *data)
{
	if (keypress == W)
		data->player_y = data->player_y - 1;
	else if (keypress == A)
		data->player_x = data->player_x - 1;
	else if (keypress == S)
		data->player_y = data->player_y + 1;
	else if (keypress == D)
		data->player_x = data->player_x + 1;
	is_collected(next_p, data);
}

int	is_exit(char next_p, t_data *data)
{
	if (next_p == 'E')
	{
		if (data->nb_c == 0)
			ft_exit(data, 1);
		else
			return (1);
	}
	return (0);
}

char	set_next_p(int keypress, t_data *data)
{
	int				x;
	int				y;
	char			**map;
	char			next_p;

	x = data->player_x;
	y = data->player_y;
	map = data->map_tab;
	next_p = '\0';
	if (keypress == ESC)
		ft_exit(data, 1);
	else if (keypress == W)
		next_p = map[y - 1][x];
	else if (keypress == A)
		next_p = map[y][x - 1];
	else if (keypress == S)
		next_p = map[y + 1][x];
	else if (keypress == D)
		next_p = map[y][x + 1];
	return (next_p);
}
