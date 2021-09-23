/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:12:59 by user42            #+#    #+#             */
/*   Updated: 2021/09/20 19:22:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(char c, int index, int size, t_data *data)
{
	if ((index == 0) || (index == size - 1))
	{
		if (c != '1')
			error_message("Error\nMap is not surrounded by walls\n", data);
	}
}

void	check_keys(t_data *data, int i, int j)
{
	char	chr;

	chr = data->map_tab[i][j];
	if ((chr != '1') && (chr != '0') && (chr != 'C')
		&& (chr != 'E') && (chr != 'P'))
		error_message("Error\nMap displayed wrong characters\n", data);
	if (chr == 'C')
		data->nb_c = data->nb_c + 1;
	else if (chr == 'E')
		data->nb_e = data->nb_e + 1;
	else if (chr == 'P')
		data->nb_p = data->nb_p + 1;
}

void	check_map(t_data *data)
{
	size_t	i;
	int		j;

	i = 0;
	while (i < data->map_length)
	{
		if (ft_strlen(data->map_tab[i]) != data->map_width)
			error_message("Error\nMap is not rectangular\n", data);
		j = 0;
		while (data->map_tab[i][j])
		{
			if (data->map_tab[i][j] == 'P')
			{
				data->player_x = j;
				data->player_y = i;
			}
			check_keys(data, i, j);
			check_walls(data->map_tab[i][j], i, data->map_length, data);
			check_walls(data->map_tab[i][j], j, data->map_width, data);
			j++;
		}
		i++;
	}
	if ((data->nb_c < 1) || (data->nb_e < 1) || (data->nb_p != 1))
		error_message("Error\nWrong character number C, E or P\n", data);
}
