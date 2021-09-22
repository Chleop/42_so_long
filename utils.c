/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 20:24:53 by user42            #+#    #+#             */
/*   Updated: 2021/09/21 14:44:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	del(char **str)
{
	if (str && (*str))
	{
		free (*str);
		*str = NULL;
	}
}

void	del_map(char ***map)
{
	int	i;

	if (map && (*map))
	{
		i = 0;
		while ((*map)[i])
		{
			del(&(*map)[i]);
			i++;
		}
		del((char **)map);
	}
}

void	ft_exit(t_data *data, int extype)
{
	if (data)
	{
		if (data->map_tab)
			del_map(&data->map_tab);
		if (data->pic_back)
			mlx_destroy_image(data->mlx_ptr, data->pic_back);
		if (data->pic_wall)
			mlx_destroy_image(data->mlx_ptr, data->pic_wall);
		if (data->pic_exit)
			mlx_destroy_image(data->mlx_ptr, data->pic_exit);
		if (data->pic_coll)
			mlx_destroy_image(data->mlx_ptr, data->pic_coll);
		if (data->pic_player)
			mlx_destroy_image(data->mlx_ptr, data->pic_player);
		if (data->pic_mouv)
			mlx_destroy_image(data->mlx_ptr, data->pic_mouv);
		if (data->win_ptr)
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		if (data->mlx_ptr)
		{
			mlx_destroy_display(data->mlx_ptr);
			free(data->mlx_ptr);
		}
	}
	exit (extype);
}

void	error_message(char *str, t_data *data)
{
	ft_putstr_fd(str, 1);
	ft_exit(data, -1);
}
