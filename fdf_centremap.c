/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_centremap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 13:11:34 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/02/24 15:03:30 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_centremap(t_map *map)
{
	int	i;
	int	j;
	int	offset_x;
	int	offset_y;

	i = 0;
	offset_x = map->points[map->lines / 2][map->width / 2].x;
	offset_y = map->points[map->lines / 2][map->width / 2].z;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->width)
		{
			map->points[i][j].x -= offset_x;
			map->points[i][j].x += 800 / 2;
			map->points[i][j].z -= offset_y;
			map->points[i][j].z += 600 / 2;
			j++;
		}
		i++;
	}
}
