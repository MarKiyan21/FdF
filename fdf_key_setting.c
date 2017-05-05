/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_setting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 13:30:44 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/02/27 12:16:08 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_key_rot(int keycode, t_map *map)
{
	if (keycode == 12)
		map->rot_y += 5;
	if (keycode == 14)
		map->rot_y -= 5;
	if (keycode == 13)
		map->rot_x += 5;
	if (keycode == 1)
		map->rot_x -= 5;
	if (keycode == 0)
		map->rot_z += 5;
	if (keycode == 2)
		map->rot_z -= 5;
}

static void	ft_key_scale(int keycode, t_map *map)
{
	if (keycode == 78)
		map->scale_x -= 1;
	if (keycode == 69)
		map->scale_x += 1;
}

static void	ft_key_y(int keycode, t_map *map)
{
	if (keycode == 24)
		map->scale_y += 1;
	if (keycode == 27)
		map->scale_y -= 1;
}

static void	ft_key_reset(t_map *map)
{
	map->rot_x = 245;
	map->rot_y = 110;
	map->rot_z = -125;
	map->scale_x = map->start_x;
	map->scale_y = map->start_y;
}

int			fdf_key_setting(int keycode, t_map *map)
{
	t_map	copy;

	copy = *map;
	copy.points = fdf_mapcpy(map);
	if (keycode == 53)
		exit(0);
	else if (keycode == 15)
		ft_key_reset(map);
	else if (keycode >= 0 && keycode <= 14)
		ft_key_rot(keycode, map);
	else if (keycode == 69 || keycode == 78)
		ft_key_scale(keycode, map);
	else if (keycode == 24 || keycode == 27)
		ft_key_y(keycode, map);
	mlx_clear_window(0, map->win);
	fdf_scale_points(&copy, copy.scale_x, copy.scale_y);
	rotate_x(map->rot_x, &copy);
	rotate_y(map->rot_y, &copy);
	rotate_z(map->rot_z, &copy);
	fdf_centremap(&copy);
	fdf_draw_map(copy);
	fdf_free_points(copy);
	return (0);
}
