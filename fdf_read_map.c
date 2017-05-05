/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:40:24 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/02/17 13:52:49 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	find_maxlen_column(char **s, int i, int j, int width)
{
	int	k;
	int	max;

	k = 0;
	max = 0;
	while (s[i])
	{
		if (width >= max)
			max = width;
		width = 0;
		while (s[i][j])
		{
			if (s[i][j] != ' ')
			{
				width++;
				while (s[i][j] && s[i][j] != ' ')
					j++;
			}
			else
				j++;
		}
		i++;
	}
	return (max);
}

static int	ft_count_lines(char *s)
{
	int		fd;
	int		lines;
	char	*line;

	lines = 0;
	if ((fd = open(s, O_RDONLY)) == -1)
	{
		ft_putstr("The file is not open! Please, try once more!\n");
		ft_putstr("Usage: ./fdf <filename>\n");
		exit(-1);
	}
	while (get_next_line(fd, &line))
	{
		lines++;
		free(line);
		line = NULL;
	}
	close(fd);
	return (lines);
}

t_map		fdf_read_map(char *filename)
{
	int		i;
	int		fd;
	char	*line;
	t_map	file;

	i = 0;
	file.map = NULL;
	if ((fd = open(filename, O_RDONLY)) == -1)
		exit(-1);
	file.lines = ft_count_lines(filename);
	if (!(file.map = (char**)malloc(sizeof(char*) * file.lines)))
		exit(0);
	while (get_next_line(fd, &line))
	{
		file.map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	file.map[i] = NULL;
	file.width = find_maxlen_column(file.map, 0, 0, 0);
	close(fd);
	return (file);
}
