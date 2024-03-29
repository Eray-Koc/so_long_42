/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erkoc <erkoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:58:06 by erkoc             #+#    #+#             */
/*   Updated: 2024/03/02 18:22:41 by erkoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strchr(char *str, int a)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == a)
			return (1);
		i++;
	}
	return (0);
}

int	count_lines(char *ber)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open(ber, O_RDONLY);
	str = malloc(sizeof(char) * 1);
	str[0] = 'a';
	while (str)
	{
		free (str);
		str = get_next_line(fd);
		i++;
	}
	return (i);
}

char	**get_map(t_solong *solong, char *ber)
{
	int		fd;
	int		i;
	char	**str;

	fd = open(ber, O_RDONLY);
	solong->mapy = count_lines(ber) - 1;
	str = malloc(sizeof(char *) * solong->mapy + 1);
	close(fd);
	fd = open(ber, O_RDONLY);
	if (fd == -1)
	{
		ft_printf(".ber file can not be opened");
		free (str);
		exit(1);
	}
	i = 0;
	while (i < solong->mapy)
	{
		str[i] = get_next_line(fd);
		i++;
	}
	str[i] = NULL;
	solong->mapx = ft_strlen(str[0]);
	return (str);
}

char	*berfilecheck(char *str)
{
	int		i;
	int		x;
	char	*ber;

	x = 0;
	ber = ".ber";
	i = ft_strlen(str) - 4;
	while (str[i])
	{
		if (str[i] != ber[x])
		{
			ft_printf("Invalid .ber file. Make sure that \
			your file extension is .ber");
			exit(1);
		}
		i++;
		x++;
	}
	return (str);
}

void	free_map(t_solong *solong, int n)
{
	int	i;

	i = -1;
	if (n == 1)
	{
		while (++i < solong->mapy)
			free(solong->map[i]);
		free(solong->map);
	}
	else
	{
		while (++i < solong->mapy)
			free(solong->mapcopy[i]);
		free(solong->mapcopy);
	}
}
