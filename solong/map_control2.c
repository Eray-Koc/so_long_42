/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erkoc <erkoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:38:18 by erkoc             #+#    #+#             */
/*   Updated: 2024/03/02 18:26:33 by erkoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flf_check(t_solong *solong)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (solong->mapcopy[i])
	{
		j = 0;
		while (solong->mapcopy[i][j])
		{
			if (ft_strchr("PEC", solong->mapcopy[i][j]))
			{
				ft_printf("Flood fill error");
				free_map(solong, 2);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	f_fill(char **tab, t_location map_size, int y, int x)
{
	if (y < 0 || x < 0)
		return ;
	if (y >= map_size.y || x >= map_size.x)
		return ;
	if (tab[y][x] == 'Z' || tab[y][x] == '1')
		return ;
	tab[y][x] = 'Z';
	f_fill(tab, map_size, y - 1, x);
	f_fill(tab, map_size, y + 1, x);
	f_fill(tab, map_size, y, x - 1);
	f_fill(tab, map_size, y, x + 1);
}

void	flood_fill(t_solong *solong)
{
	t_location	character;
	t_location	map;

	solong->mapcopy = get_map(solong, solong->mapname);
	character.x = solong->chrx;
	character.y = solong->chry;
	map.x = solong->mapx;
	map.y = solong->mapy;
	f_fill(solong->mapcopy, map, character.y, character.x);
	flf_check(solong);
	free_map(solong, 2);
}
