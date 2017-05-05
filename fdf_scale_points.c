/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_scale_points.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:52:56 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/02/17 12:54:49 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_scale_points(t_map *map, int scale_x, int scale_y)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->width)
		{
			map->points[i][j].x *= scale_x;
			map->points[i][j].y *= scale_y;
			map->points[i][j].z *= scale_x;
			j++;
		}
		i++;
	}
}
