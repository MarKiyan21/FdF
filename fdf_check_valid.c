/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_check_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:23:07 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/02/18 13:49:44 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf_check_valid(int ac, char **av)
{
	if (ac == 2)
		return (2);
	if (ac != 4)
	{
		ft_putstr("\x1b[31;3mUsage: ./fdf <filename>\n\x1b[0m");
		ft_putstr("\x1b[33;1mOr you can specify the scale of the drawing\n\
\x1b[0m");
		ft_putstr("\x1b[31;3mUsage: ./fdf <filename>\x1b[0m \x1b[32;1m\
[scale_X\x1b[0m x \x1b[32;1mscale_Y]\x1b[0m\nTry again\n");
		exit(-1);
	}
	if (ac == 4)
	{
		if ((ft_atoi(av[2]) <= 0) || (ft_atoi(av[3]) <= 0))
		{
			ft_putstr("Please, use coordinates greater than 0\n");
			exit(-1);
		}
		return (4);
	}
	return (0);
}
