/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erkoc <erkoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:44:58 by erkoc             #+#    #+#             */
/*   Updated: 2024/03/03 13:28:02 by erkoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	resetvalues(t_solong *solong)
{
	solong->mapy = 0;
	solong->mapx = 0;
	solong->p_count = 0;
	solong->c_count = 0;
	solong->e_count = 0;
	solong->move_count = 0;
	solong->collected_count = 0;
	solong->chrx = 0;
	solong->chry = 0;
	solong->exitx = 0;
	solong->exity = 0;
}

int	ft_key(int keycode, t_solong *solong)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (keycode == 13)
		ft_up(solong);
	else if (keycode == 0)
		ft_left(solong);
	else if (keycode == 2)
		ft_right(solong);
	else if (keycode == 1)
		ft_down(solong);
	else if (keycode == 53)
		ft_close(solong);
	put_image(solong, x, y);
}

void	upload_image(t_solong *solong)
{
	int	x;
	int	y;

	solong->exit = mlx_xpm_file_to_image(solong->mlx, \
	"img/exit.xpm", &x, &y);
	solong->player = mlx_xpm_file_to_image(solong->mlx, \
	"img/lightningmq.xpm", &x, &y);
	solong->collectable = mlx_xpm_file_to_image(solong->mlx, \
	"img/collectable.xpm", &x, &y);
	solong->wall = mlx_xpm_file_to_image(solong->mlx, \
	"img/rock1.xpm", &x, &y);
	solong->freespace = mlx_xpm_file_to_image(solong->mlx, \
	"img/road.xpm", &x, &y);
	if (!solong->exit || !solong->player || !solong->collectable \
	|| !solong->wall || !solong->freespace)
	{
		ft_printf("Missing image");
		exit(1);
	}
}

void	put_image(t_solong *solong, int x, int y)
{
	y = 0;
	while (solong->map[y])
	{
		x = 0;
		while (solong->map[y][x])
		{
			if (solong->map[y][x] == '1')
				mlx_put_image_to_window(solong->mlx, solong->mlx_win,
					solong->wall, x * 64, y * 64);
			else if (solong->map[y][x] == '0')
				mlx_put_image_to_window(solong->mlx, solong->mlx_win,
					solong->freespace, x * 64, y * 64);
			else if (solong->map[y][x] == 'P')
				mlx_put_image_to_window(solong->mlx, solong->mlx_win,
					solong->player, x * 64, y * 64);
			else if (solong->map[y][x] == 'E')
				mlx_put_image_to_window(solong->mlx, solong->mlx_win,
					solong->exit, x * 64, y * 64);
			else if (solong->map[y][x] == 'C')
				mlx_put_image_to_window(solong->mlx, solong->mlx_win,
					solong->collectable, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

int	main(int ac, char **arg)
{
	int			x;
	int			y;
	t_solong	*solong;

	if (ac != 2)
	{
		ft_printf("Insufficient argument");
		exit(1);
	}
	solong = malloc(sizeof(t_solong));
	resetvalues(solong);
	solong->mapname = berfilecheck(arg[1]);
	solong->map = get_map(solong, solong->mapname);
	mapsize_check(solong, x, y);
	flood_fill(solong);
	solong->mlx = mlx_init();
	solong->mlx_win = mlx_new_window(solong->mlx, \
	solong->mapx * 64, solong->mapy * 64, "So Long");
	upload_image(solong);
	put_image(solong, x, y);
	mlx_key_hook(solong->mlx_win, ft_key, solong);
	mlx_hook(solong->mlx_win, 17, 0, ft_close, solong);
	mlx_loop(solong->mlx);
}
