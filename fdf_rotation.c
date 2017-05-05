/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:56:43 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/02/27 15:43:47 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(float nb, t_map *map)
{
	int		i;
	int		j;
	float	y;
	float	z;

	i = 0;
	nb = nb * 0.01745329252;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->width)
		{
			z = map->points[i][j].z * cos(nb) - map->points[i][j].y * sin(nb);
			y = map->points[i][j].y * cos(nb) + map->points[i][j].z * sin(nb);
			map->points[i][j].y = y;
			map->points[i][j].z = z;
			j++;
		}
		i++;
	}
}

void	rotate_y(float nb, t_map *map)
{
	int		i;
	int		j;
	float	x;
	float	z;

	i = 0;
	nb = nb * 0.01745329252;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->width)
		{
			x = map->points[i][j].z * cos(nb) + map->points[i][j].x * sin(nb);
			z = map->points[i][j].x * cos(nb) - map->points[i][j].z * sin(nb);
			map->points[i][j].x = x;
			map->points[i][j].z = z;
			j++;
		}
		i++;
	}
}

void	rotate_z(float nb, t_map *map)
{
	int		i;
	int		j;
	float	x;
	float	y;

	i = 0;
	nb = nb * 0.01745329252;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->width)
		{
			x = map->points[i][j].y * cos(nb) - map->points[i][j].x * sin(nb);
			y = map->points[i][j].y * sin(nb) + map->points[i][j].x * cos(nb);
			map->points[i][j].x = x;
			map->points[i][j].y = y;
			j++;
		}
		i++;
	}
}
