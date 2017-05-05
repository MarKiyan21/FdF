/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:33:07 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/02/17 12:41:18 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_free_map(t_map map)
{
	int	i;

	i = 0;
	while (i < map.lines)
	{
		free(map.map[i]);
		i++;
	}
	free(map.map);
	map.map = NULL;
}

void	fdf_free_points(t_map map)
{
	int	i;

	i = 0;
	while (i < map.lines)
	{
		free(map.points[i]);
		i++;
	}
	free(map.points);
	map.points = NULL;
}
