/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:55:25 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/02/17 19:24:50 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_write_color(char *s, int i)
{
	char	*col;
	int		color;

	while (s[i] && s[i] != ' ' && s[i] != ',')
		i++;
	if (s[i] == ',')
	{
		while (s[i] && s[i] != 'x')
			i++;
		col = ft_strsub(s, i + 1, 6);
		color = ft_atoi_base(col, 16);
		i++;
	}
	else
		color = 0xffffff;
	return (color);
}

static int		ft_find_y(char *s)
{
	int		i;
	int		k;
	char	*buff;
	int		coord_y;

	i = 0;
	k = 0;
	while (s[k] && s[k] != ',')
		k++;
	buff = ft_strsub(s, i, k - 1);
	coord_y = ft_atoi(buff);
	free(buff);
	return (coord_y);
}

static t_coord	ft_new_point(int x, int y, int z, int col)
{
	t_coord	new;

	new.x = x;
	new.y = y;
	new.z = z;
	new.color = col;
	return (new);
}

void			fdf_map(t_map *map, t_coord ***points)
{
	int		i;
	int		j;
	char	**split;
	t_coord	**new;

	i = 0;
	if (!(new = (t_coord**)malloc(sizeof(t_coord*) * map->lines)))
		exit(0);
	while (i < map->lines)
	{
		if (!(new[i] = (t_coord*)malloc(sizeof(t_coord) * map->width)))
			exit(0);
		j = 0;
		split = ft_strsplit(map->map[i], ' ');
		while (j < map->width && split[j])
		{
			new[i][j] = ft_new_point(j, ft_find_y(split[j]), i,\
			ft_write_color(split[j], 0));
			j++;
		}
		free(split);
		i++;
	}
	*points = new;
}
