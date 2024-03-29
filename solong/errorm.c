/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erkoc <erkoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:27:36 by erkoc             #+#    #+#             */
/*   Updated: 2024/03/02 18:45:24 by erkoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	errormessage(t_solong *solong, char c)
{
	if (c == 'f')
	{
		free_map(solong, 1);
		free_map(solong, 2);
		ft_printf("Flood fill error");
	}
	else if (c == 'm')
	{
		free_map(solong, 1);
		ft_printf("Map size error");
	}
	else if (c == 'g')
	{
		free_map(solong, 1);
		ft_printf("There's a gap on the wall.");
	}
	else
	{
		errormessage2(solong, c);
	}
	free(solong);
	mlx_destroy_window(solong->mlx, solong->mlx_win);
	exit(1);
}

void	errormessage2(t_solong *solong, char c)
{
	if (c == 'c')
	{
		free_map(solong, 1);
		ft_printf("There's a component that shouldn't exist in map");
	}
	else if (c == 'a')
	{
		free_map(solong, 1);
		ft_printf("Invalid component amount");
	}
	else if (c == 'w')
	{
		free_map(solong, 1);
		ft_printf("Congratulations, you won. Kacchoww!");
	}
	free(solong);
	mlx_destroy_window(solong->mlx, solong->mlx_win);
	exit(1);
}
