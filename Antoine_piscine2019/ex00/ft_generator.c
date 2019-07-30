/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_generator.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/23 11:38:48 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 23:17:18 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lib.h"

char	**ft_map2d(char *map1d, char **map2d, int size_x, int y)
{
	int		x1;
	int		x2;
	int		y1;

	x1 = 1;
	x2 = 0;
	y1 = 0;
	while (y1 < y - 1)
	{
		while (map1d[x1 - 1] != '\n' && y1 == 0)
			x1++;
		if (!(map2d[y1] = malloc(sizeof(char **) * (size_x + 1))))
			return (0);
		while (map1d[x1] != '\n' && map1d[x1] != '\0')
			map2d[y1][x2++] = map1d[x1++];
		map2d[y1][x2] = map1d[x1];
		x1++;
		x2++;
		map2d[y1][x2] = '\0';
		x2 = 0;
		y1++;
	}
	map2d[y1] = 0;
	return (map2d);
}

char	**ft_map2d_generator(char *map1d, char **map2d)
{
	int		x;
	int		y;
	int		size_x;

	x = 0;
	y = 0;
	size_x = 0;
	while (map1d[x] != '\0')
	{
		if (map1d[x] == '\n')
			y++;
		if (y == 1)
			size_x++;
		x++;
	}
	if (!(map2d = malloc(sizeof(char *) * (y + 1))))
		return (0);
	return (ft_map2d(map1d, map2d, size_x, y));
}

int		ft_map_size(char *av)
{
	int		dict;
	int		ret;
	int		i;
	char	buff[BUFF_SIZE + 1000000];

	i = 0;
	dict = open(av, O_RDONLY);
	if (dict == -1)
		return (0);
	while ((ret = read(dict, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		i++;
	}
	return (i);
}

char	*ft_map1d_generator(int size, char *av, char *map1d)
{
	int		dict;
	int		ret;
	int		i;
	int		cpt;
	char	buff[BUFF_SIZE + 1];

	dict = open(av, O_RDONLY);
	i = 0;
	cpt = 0;
	if (!(map1d = malloc(sizeof(char) * (size + 1))))
		return (0);
	if (dict == -1)
		return (0);
	while ((ret = read(dict, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		map1d[i] = buff[0];
		i++;
	}
	return (map1d);
}

char	*ft_param(char *map1d)
{
	int		i;
	int		j;
	char	*map1d_v2;

	i = 0;
	j = 0;
	while (map1d[i + j] != '\0' && map1d[i + j] != '\n')
	{
		if (map1d[i + j] != '\n')
			j++;
	}
	if (!(map1d_v2 = malloc(sizeof(char) * (j + 1))))
		return (0);
	while (map1d[i] != '\n' && map1d[i] != '\0')
	{
		map1d_v2[i] = map1d[i];
		i++;
	}
	map1d_v2[i] = '\0';
	return (map1d_v2);
}
