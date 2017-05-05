/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:03:43 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/02/17 17:20:04 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include "mlx.h"
# include "libft/libft.h"

typedef struct		s_coord
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_coord;

typedef struct		s_map
{
	char			**map;
	int				lines;
	int				width;
	void			*mlx;
	void			*win;
	t_coord			**points;
	int				scale_x;
	int				scale_y;
	float			rot_x;
	float			rot_y;
	float			rot_z;
	int				start_x;
	int				start_y;
}					t_map;

int					main(int ac, char **av);
int					fdf_check_valid(int ac, char **av);
t_map				fdf_read_map(char *filename);
void				fdf_map(t_map *map, t_coord ***points);
void				fdf_free_map(t_map map);
void				fdf_free_points(t_map map);
void				fdf_init_map(t_map *map);
void				fdf_draw_map(t_map map);
t_coord				**fdf_mapcpy(t_map *map);
void				fdf_scale_points(t_map *map, int scale_x, int scale_y);
void				rotate_x(float nb, t_map *map);
void				rotate_y(float nb, t_map *map);
void				rotate_z(float nb, t_map *map);
void				fdf_centremap(t_map *map);
void				fdf_draw_line(t_coord a, t_coord b, t_map *m);
int					fdf_key_setting(int keycode, t_map *map);

#endif
