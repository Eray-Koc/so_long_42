/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erkoc <erkoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:46:39 by erkoc             #+#    #+#             */
/*   Updated: 2024/03/03 13:50:51 by erkoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_up(t_solong *solong)
{
	if (solong->map[solong->chry - 1][solong->chrx] != '1')
	{
		solong->move_count++;
		ft_printf("Move Count: %d\n", solong->move_count);
		if (solong->map[solong->chry - 1][solong->chrx] == 'C')
			solong->collected_count++;
		else if (solong->map[solong->chry -1][solong->chrx] == 'E')
		{
			if (solong->c_count == solong->collected_count)
				errormessage(solong, 'w');
			solong->map[solong->chry][solong->chrx] = '0';
			solong->chry--;
			solong->map[solong->chry][solong->chrx] = 'P';
			return ;
		}
		solong->map[solong->chry][solong->chrx] = '0';
		solong->chry--;
		solong->map[solong->chry][solong->chrx] = 'P';
		if (solong->map[solong->exity][solong->exitx] != 'E')
			solong->map[solong->exity][solong->exitx] = 'E';
	}
}

void	ft_left(t_solong *solong)
{
	if (solong->map[solong->chry][solong->chrx - 1] != '1')
	{
		solong->move_count++;
		ft_printf("Move Count: %d\n", solong->move_count);
		if (solong->map[solong->chry][solong->chrx - 1] == 'C')
			solong->collected_count++;
		else if (solong->map[solong->chry][solong->chrx - 1] == 'E')
		{
			if (solong->c_count == solong->collected_count)
				errormessage(solong, 'w');
			solong->map[solong->chry][solong->chrx] = '0';
			solong->chrx--;
			solong->map[solong->chry][solong->chrx] = 'P';
			return ;
		}
		solong->map[solong->chry][solong->chrx] = '0';
		solong->chrx--;
		solong->map[solong->chry][solong->chrx] = 'P';
		if (solong->map[solong->exity][solong->exitx] != 'E')
			solong->map[solong->exity][solong->exitx] = 'E';
	}
}

void	ft_right(t_solong *solong)
{
	if (solong->map[solong->chry][solong->chrx + 1] != '1')
	{
		solong->move_count++;
		ft_printf("Move Count: %d\n", solong->move_count);
		if (solong->map[solong->chry][solong->chrx + 1] == 'C')
			solong->collected_count++;
		else if (solong->map[solong->chry][solong->chrx + 1] == 'E')
		{
			if (solong->c_count == solong->collected_count)
				errormessage(solong, 'w');
			solong->map[solong->chry][solong->chrx] = '0';
			solong->chrx++;
			solong->map[solong->chry][solong->chrx] = 'P';
			return ;
		}
		solong->map[solong->chry][solong->chrx] = '0';
		solong->chrx++;
		solong->map[solong->chry][solong->chrx] = 'P';
		if (solong->map[solong->exity][solong->exitx] != 'E')
			solong->map[solong->exity][solong->exitx] = 'E';
	}
}

void	ft_down(t_solong *solong)
{
	if (solong->map[solong->chry + 1][solong->chrx] != '1')
	{
		solong->move_count++;
		ft_printf("Move Count: %d\n", solong->move_count);
		if (solong->map[solong->chry + 1][solong->chrx] == 'C')
			solong->collected_count++;
		else if (solong->map[solong->chry + 1][solong->chrx] == 'E')
		{
			if (solong->c_count == solong->collected_count)
				errormessage(solong, 'w');
			solong->map[solong->chry][solong->chrx] = '0';
			solong->chry++;
			solong->map[solong->chry][solong->chrx] = 'P';
			return ;
		}
		solong->map[solong->chry][solong->chrx] = '0';
		solong->chry++;
		solong->map[solong->chry][solong->chrx] = 'P';
		if (solong->map[solong->exity][solong->exitx] != 'E')
			solong->map[solong->exity][solong->exitx] = 'E';
	}
}

void	ft_close(t_solong *solong)
{
	ft_printf("Game closed.");
	free_map(solong, 1);
	exit(1);
}
