/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 13:21:58 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/02/17 15:59:19 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	ft_abs(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

static float	ft_max(float a, float b)
{
	if (a < b)
		return (b);
	return (a);
}

void			fdf_draw_line(t_coord a, t_coord b, t_map *map)
{
	int		col;
	float	step;
	float	i;
	t_coord	point;

	i = 0;
	if (a.color <= b.color)
		col = a.color;
	else
		col = b.color;
	step = (float)(1 / (ft_max(ft_abs(a.x - b.x), ft_abs(a.z - b.z)) * 2));
	while (i <= 1)
	{
		point.x = a.x + i * (b.x - a.x);
		point.y = a.y + i * (b.y - a.y);
		point.z = a.z + i * (b.z - a.z);
		mlx_pixel_put(map->mlx, map->win, point.x, point.z, col);
		i = i + step;
	}
}
