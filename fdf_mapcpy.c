/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mapcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:45:37 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/02/17 12:49:13 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	**fdf_mapcpy(t_map *map)
{
	int		i;
	int		j;
	t_coord	**new;

	i = 0;
	if (!(new = (t_coord**)malloc(sizeof(t_coord*) * map->lines)))
		return (NULL);
	while (i < map->lines)
	{
		if (!(new[i] = (t_coord*)malloc(sizeof(t_coord) * map->width)))
			return (NULL);
		j = 0;
		while (j < map->width)
		{
			new[i][j] = map->points[i][j];
			j++;
		}
		i++;
	}
	return (new);
}
