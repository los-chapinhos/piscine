/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_resolve.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/23 20:20:38 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 22:06:36 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lib.h"

int		ft_check(t_pos pos, int size_kr, char *map1d, char **map2d)
{
	int		save_j;
	int		save_kr;

	save_j = pos.j_v2;
	save_kr = size_kr;
	while (size_kr >= 0)
	{
		if (map2d[pos.i_v2][pos.j_v2] == map1d[ft_strlen_v2(map1d) - 2])
			return (0);
		pos.j_v2--;
		size_kr--;
	}
	while (save_kr >= 0)
	{
		if (map2d[pos.i_v2][save_j] == map1d[ft_strlen_v2(map1d) - 2])
			return (0);
		pos.i_v2--;
		save_kr--;
	}
	return (1);
}

int		ft_resolve_square(t_pos pos, char *map1d, char **map2d, int size_krmax)
{
	int		size_kr;

	size_kr = 0;
	pos.i_v2 = pos.i + size_kr;
	pos.j_v2 = pos.j + size_kr;
	while (ft_check(pos, size_kr, map1d, map2d) == 1 &&
			pos.i_v2 < pos.len_y - 1 && pos.j_v2 < pos.len_x)
	{
		if (pos.i_v2 < pos.len_y - 1)
			size_kr++;
		else
			pos.j_v2++;
		pos.i_v2 = pos.i + size_kr;
		if (pos.i_v2 < pos.len_y - 1)
			pos.j_v2 = pos.j + size_kr;
	}
	if (size_kr > size_krmax)
		return (size_kr);
	return (size_krmax);
}

char	**ft_fill_final(char *map1d, char **map2d)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map2d[i][j] != '\0')
	{
		if (map2d[i][j] != map1d[ft_strlen_v2(map1d) - 2] &&
				map2d[i][j] != '\n')
		{
			map2d[i][j] = map1d[ft_strlen_v2(map1d) - 1];
			return (map2d);
		}
		j++;
	}
	return (map2d);
}

char	**ft_fill(t_pos pos, char *map1d, char **map2d)
{
	int i;
	int j;
	int save_j;

	save_j = pos.jmax;
	j = 0;
	i = pos.krpos;
	if (pos.len_y == 1)
		return (ft_fill_final(map1d, map2d));
	while (pos.krpos >= 0)
	{
		while (j <= i)
		{
			map2d[pos.imax][pos.jmax] = map1d[ft_strlen_v2(map1d) - 1];
			pos.jmax++;
			j++;
		}
		j = 0;
		pos.jmax = save_j;
		pos.imax++;
		pos.krpos--;
	}
	return (map2d);
}

char	**ft_resolve(t_pos pos, char *map1d, char **map2d)
{
	int		size_krmax;

	size_krmax = 0;
	pos.i = 0;
	pos.j = 0;
	pos.krpos = 0;
	while (map2d[pos.i] != '\0')
	{
		while (map2d[pos.i][pos.j] != '\n')
		{
			if (map2d[pos.i][pos.j] != map1d[ft_strlen_v2(map1d) - 2])
				size_krmax = ft_resolve_square(pos, map1d, map2d, size_krmax);
			if (pos.krpos < size_krmax)
			{
				pos.krpos = size_krmax;
				pos.imax = pos.i;
				pos.jmax = pos.j;
			}
			pos.j++;
		}
		pos.j = 0;
		pos.i++;
	}
	return (ft_fill(pos, map1d, map2d));
}
