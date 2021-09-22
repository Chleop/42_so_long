/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:17:29 by user42            #+#    #+#             */
/*   Updated: 2021/09/21 14:50:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_variables(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->map_tab = NULL;
	data->map_width = 0;
	data->map_length = 0;
	data->player_x = 0;
	data->player_y = 0;
	data->nb_c = 0;
	data->nb_e = 0;
	data->nb_p = 0;
	data->pic_back = NULL;
	data->pic_wall = NULL;
	data->pic_exit = NULL;
	data->pic_coll = NULL;
	data->pic_player = NULL;
	data->pic_mouv = NULL;
	data->pic_width = 0;
	data->pic_height = 0;
	data->mouv = 0;
}

void	file_to_image(t_data *data)
{
	int	*w;
	int	*h;

	w = &data->pic_width;
	h = &data->pic_height;
	data->pic_back = mlx_xpm_file_to_image(data->mlx_ptr, PIC_BACK, w, h);
	if (!data->pic_back)
		error_message("Error\nMlx_xpm_file_to_image back failed\n", data);
	data->pic_wall = mlx_xpm_file_to_image(data->mlx_ptr, PIC_WALL, w, h);
	if (!data->pic_wall)
		error_message("Error\nMlx_xpm_file_to_image wall failed\n", data);
	data->pic_exit = mlx_xpm_file_to_image(data->mlx_ptr, PIC_EXIT, w, h);
	if (!data->pic_exit)
		error_message("Error\nMlx_xpm_file_to_image exit failed\n", data);
	data->pic_coll = mlx_xpm_file_to_image(data->mlx_ptr, PIC_COLL, w, h);
	if (!data->pic_coll)
		error_message("Error\nMlx_xpm_file_to_image coll failed\n", data);
	data->pic_player = mlx_xpm_file_to_image(data->mlx_ptr, PIC_PLAYER, w, h);
	if (!data->pic_player)
		error_message("Error\nMlx_xpm_file_to_image player failed\n", data);
	data->pic_mouv = mlx_xpm_file_to_image(data->mlx_ptr, PIC_MOUV, w, h);
	if (!data->pic_mouv)
		error_message("Error\nMlx_xpm_file_to_image mouv failed\n", data);
}

void	init_game(t_data *data)
{
	int	w;
	int	l;

	w = data->map_width;
	l = data->map_length;
	data->pic_width = 60;
	data->pic_height = 60;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		error_message("Error\nMlx_init failed\n", data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, w * 60, l * 60 + 60, "sol_b");
	if (!data->win_ptr)
		error_message("Error\nMlx_new_window failed\n", data);
	file_to_image(data);
}
