/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:16:27 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/02/18 17:12:46 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_init_map(t_map *map, char **av, int flag)
{
	if (flag == 4)
	{
		map->scale_x = ft_atoi(av[2]);
		map->scale_y = ft_atoi(av[3]);
	}
	else
	{
		map->scale_x = 20;
		map->scale_y = 20;
	}
	map->start_x = map->scale_x;
	map->start_y = map->scale_y;
}

int			main(int ac, char **av)
{
	int		flag;
	t_map	map;

	flag = fdf_check_valid(ac, av);
	map = fdf_read_map(av[1]);
	ft_init_map(&map, av, flag);
	fdf_map(&map, &map.points);
	fdf_free_map(map);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, 800, 600, "FdF");
	fdf_init_map(&map);
	mlx_hook(map.win, 2, 3, fdf_key_setting, &map);
	mlx_loop(map.mlx);
}
