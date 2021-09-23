/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:58:43 by user42            #+#    #+#             */
/*   Updated: 2021/09/23 12:10:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*print_mvmts(t_data *data)
{
	char	*str;
	char	*s1;

	s1 = ft_itoa(data->mouv);
	if (!s1)
		ft_exit(data, -1);
	str = ft_strjoin("Mouvements : ", s1);
	del(&s1);
	if (!str)
		ft_exit(data, -1);
	return (str);
}

void	make_mouv(char next_p, int keypress, t_data *data)
{
	char	*mouv;
	int		x;
	int		y;
	void	*mlx;
	void	*win;

	mlx = data->mlx_ptr;
	win = data->win_ptr;
	x = (data->map_width - 1) * 30;
	y = (data->map_length * 60) + 30;
	data->map_tab[data->player_y][data->player_x] = '0';
	mouvement(next_p, keypress, data);
	data->map_tab[data->player_y][data->player_x] = 'P';
	data->mouv = data->mouv + 1;
	mlx_put_image_to_window(mlx, win, data->pic_mouv, 0, data->map_length * 60);
	mouv = print_mvmts(data);
	mlx_string_put(mlx, win, x, y, 0x09E137, mouv);
	free(mouv);
}
