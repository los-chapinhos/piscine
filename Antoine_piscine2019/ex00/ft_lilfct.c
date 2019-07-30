/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lilfct.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 21:56:18 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 23:36:39 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lib.h"
#include <stdio.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int		ft_strlen_v2(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_line(char **map2d)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map2d[i])
	{
		while (map2d[i][j])
		{
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_display(char **map2d)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map2d[i] != '\0')
	{
		while (map2d[i][j] != '\0')
		{
			write(1, &map2d[i][j], 1);
			j++;
		}
		j = 0;
		i++;
	}
}

char	**ft_pre_resolve(char *map1d, char **map2d)
{
	t_pos pos;

	pos.len_x = ft_strlen(map2d[0]);
	pos.len_y = ft_line(map2d);
	return (ft_resolve(pos, map1d, map2d));
}
