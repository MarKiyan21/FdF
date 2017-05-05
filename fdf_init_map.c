/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:42:42 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/02/27 15:39:52 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_draw_instruct(t_map map)
{
	int	col;

	col = 0x009966;
	mlx_string_put(map.mlx, map.win, 5, 5, col, "W and S for x rotation");
	mlx_string_put(map.mlx, map.win, 5, 20, col, "A and D for y rotation");
	mlx_string_put(map.mlx, map.win, 5, 35, col, "Q and E for z rotation");
	mlx_string_put(map.mlx, map.win, 5, 50, col, "+ and - for increase\
	/decrease y");
	mlx_string_put(map.mlx, map.win, 5, 65, col, "NUM+ and NUM- for zoom");
	mlx_string_put(map.mlx, map.win, 5, 80, col, "R to reset");
}

void		fdf_draw_map(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.lines)
	{
		j = 0;
		while (j < map.width)
		{
			if (i < map.lines - 1)
				fdf_draw_line(map.points[i][j], map.points[i + 1][j], &map);
			if (j < map.width - 1)
				fdf_draw_line(map.points[i][j], map.points[i][j + 1], &map);
			j++;
		}
		i++;
	}
	ft_draw_instruct(map);
}

void		fdf_init_map(t_map *map)
{
	t_map	copy;

	map->rot_x = 245;
	map->rot_y = 110;
	map->rot_z = -125;
	copy = *map;
	copy.points = fdf_mapcpy(map);
	fdf_scale_points(&copy, map->scale_x, map->scale_y);
	rotate_x(map->rot_x, &copy);
	rotate_y(map->rot_y, &copy);
	rotate_z(map->rot_z, &copy);
	fdf_centremap(&copy);
	fdf_draw_map(copy);
	fdf_free_points(copy);
}
