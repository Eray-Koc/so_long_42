/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erkoc <erkoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:42:02 by erkoc             #+#    #+#             */
/*   Updated: 2024/02/10 13:42:04 by erkoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		ft_exists(char *str, char c);
int		ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *dst, char *src);
char	*ft_readline(int fd, char *dst);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif