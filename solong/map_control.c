/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erkoc <erkoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:58:15 by erkoc             #+#    #+#             */
/*   Updated: 2024/03/10 15:59:43 by erkoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	countcheck(t_solong *solong)
{
	if (solong->e_count != 1 || \
	solong->p_count != 1 || solong->c_count < 1)
	{
		ft_printf("Invalid component amount");
		exit(1);
	}
}

void	getlocation(t_solong *solong, int y, int x)
{
	y = -1;
	while (++y < solong->mapy)
	{
		x = 0;
		while (x < solong->mapx)
		{
			if (solong->map[y][x] == 'P')
			{
				solong->p_count += 1;
				solong->chrx = x;
				solong->chry = y;
			}
			else if (solong->map[y][x] == 'E')
			{
				solong->e_count += 1;
				solong->exitx = x;
				solong->exity = y;
			}
			else if (solong->map[y][x] == 'C')
				solong->c_count += 1;
			x++;
		}
	}
	countcheck(solong);
}

void	componentcheck(t_solong *solong, int i, int j)
{
	i = 0;
	while (solong->map[i])
	{
		j = 0;
		while (solong->map[i][j])
		{
			if (!ft_strchr("01PEC", solong->map[i][j]))
			{
				ft_printf("There's a component that shouldn't exist in map");
				exit(1);
			}
			j++;
		}
		i++;
	}
	getlocation(solong, i, j);
}

void	wallcheck(t_solong *solong, int y, int x)
{
	y = 0;
	while (y < solong->mapy)
	{
		x = 0;
		while (x < solong->mapx)
		{
			if ((x == solong->mapx - 1 || x == 0) && solong->map[y][x] != '1')
			{
				ft_printf("There's a gap on the wall. \
				Make sure that the map is covered with 1");
				exit(1);
			}
			if ((y == solong->mapy - 1 || y == 0) && solong->map[y][x] != '1')
			{
				ft_printf("There's a gap on the wall. \
				Make sure that the map is covered with 1");
				exit(1);
			}
			x++;
		}
		y++;
	}
	componentcheck(solong, x, y);
}

void	mapsize_check(t_solong *solong, int y, int i)
{
	int	z;

	z = 0;
	i = 0;
	y = ft_strlen(solong->map[0]);
	while (i < solong->mapy)
	{
		if (y != ft_strlen(solong->map[i]))
		{
			ft_printf("Map size error");
			exit(1);
		}
		i++;
	}
	if (y > 40 || solong->mapy > 22)
	{
		ft_printf("The map is too big");
		exit(1);
	}
	wallcheck(solong, y, i);
}
