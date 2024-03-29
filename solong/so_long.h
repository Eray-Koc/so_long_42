/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erkoc <erkoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:50:53 by erkoc             #+#    #+#             */
/*   Updated: 2024/03/02 19:18:49 by erkoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "mlx/mlx.h"

typedef struct s_solong
{
	char	**map;
	char	**mapcopy;
	char	*mapname;
	int		mapy;
	int		mapx;
	int		p_count;
	int		c_count;
	int		e_count;
	int		move_count;
	int		collected_count;
	int		chrx;
	int		chry;
	int		exity;
	int		exitx;
	void	*exit;
	void	*collectable;
	void	*player;
	void	*wall;
	void	*freespace;
	void	*mlx;
	void	*mlx_win;

}				t_solong;

typedef struct s_location
{
	int	x;
	int	y;
}				t_location;
char	**get_map(t_solong *solong, char *ber);
void	componentcheck(t_solong *solong, int i, int j);
int		count_lines(char *ber);
int		ft_strchr(char *str, int a);
void	wallcheck(t_solong *solong, int y, int x);
void	getlocation(t_solong *solong, int y, int x);
void	mapsize_check(t_solong *solong, int y, int i);
char	*berfilecheck(char *str);
void	flf_check(t_solong *solong);
void	f_fill(char **tab, t_location map_size, int y, int x);
void	flood_fill(t_solong *solong);
void	upload_image(t_solong *solong);
void	put_image(t_solong *solong, int x, int y);
int		ft_key(int keycode, t_solong *solong);
void	ft_up(t_solong *solong);
void	ft_left(t_solong *solong);
void	ft_right(t_solong *solong);
void	ft_down(t_solong *solong);
void	resetvalues(t_solong *solong);
void	free_map(t_solong *solong, int n);
void	errormessage(t_solong *solong, char c);
void	errormessage2(t_solong *solong, char c);
void	ft_close(t_solong *solong);
#endif