/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:12:02 by user42            #+#    #+#             */
/*   Updated: 2021/09/21 14:41:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	init_variables(&data);
	if (argc == 2)
	{
		open_map(argv[1], &data);
		check_map(&data);
		init_game(&data);
		display_game(data);
	}
	else
		error_message ("Error\nNot the right number of arguments\n", NULL);
	return (0);
}
