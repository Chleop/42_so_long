/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 20:17:52 by user42            #+#    #+#             */
/*   Updated: 2021/09/22 11:55:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_map_dimensions(char *map_address, t_data *data)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(map_address, O_RDONLY);
	if (fd < 0)
		error_message("Error\nOpen failed\n", NULL);
	line = get_next_line(fd);
	if (!line)
		error_message("Error\nEmpty file\n", data);
	i = 0;
	data->map_width = ft_strlen(line) - 1;
	while (line)
	{
		i++;
		del(&line);
		line = get_next_line(fd);
	}
	del(&line);
	data->map_length = i;
	if (data->map_width > 32 || data->map_length > 18)
		error_message("Error\nMap is to big!\n", data);
}

char	**fill_map(int fd, size_t length)
{
	size_t	i;
	char	**map;

	i = 0;
	map = malloc(sizeof (char *) * (length + 1));
	if (!map)
	{
		error_message("Error\nMap malloc failed\n", NULL);
		return (NULL);
	}
	while (i < length)
	{
		map[i] = get_next_line(fd);
		if ((ft_strchr(map[i], '\n')))
			*(ft_strchr(map[i], '\n')) = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	open_map(char *map_address, t_data *data)
{
	int		fd;
	int		dot_position;
	char	*ext;

	dot_position = (ft_strchr(map_address, '.')) - map_address;
	ext = ft_substr(map_address, dot_position, 5);
	if (!ext)
		error_message("Error\nExtension malloc failed\n", NULL);
	if (ft_strncmp(".ber", ext, 5))
	{
		free(ext);
		error_message("Error\nWrong extension (.ber needed)\n", NULL);
	}
	free(ext);
	find_map_dimensions(map_address, data);
	fd = open(map_address, O_RDONLY);
	if (fd < 0)
		error_message("Error\nOpen failed\n", NULL);
	data->map_tab = fill_map(fd, data->map_length);
}
