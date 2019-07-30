/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/22 12:59:36 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 23:19:55 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lib.h"

int		ft_error1(int i, char **map2d)
{
	i = 0;
	if (map2d[i] == '\0')
		return (0);
	return (1);
}

t_param	ft_cpt_line(t_param param, int i, char *map1d)
{
	i = 0;
	while (map1d[i] != '\0')
		i++;
	param.cv = map1d[i - 3];
	param.co = map1d[i - 2];
	param.cp = map1d[i - 1];
	param.line = 0;
	i = 0;
	while (map1d[i] >= '0' && map1d[i] <= '9' &&
			map1d[i + 3] != '\0')
	{
		param.line = param.line * 10;
		param.line = param.line + map1d[i] - '0';
		i++;
	}
	return (param);
}

int		ft_error2(int i, int j, char *map1d, char **map2d)
{
	t_size	size;
	t_param	param;

	param.cv = '0';
	param.co = '0';
	param.cp = '0';
	i = 0;
	param = ft_cpt_line(param, i, map1d);
	size.good_size_map = ft_strlen(map2d[i]);
	while (map2d[i] != '\0')
	{
		size.size_map = ft_strlen(map2d[i]);
		while (map2d[i][j] != '\n')
		{
			if (size.good_size_map != size.size_map || (map2d[i][j] != param.cv
				&& map2d[i][j] != param.co && map2d[i][j] != param.cp))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	if (param.line != i)
		return (0);
	return (1);
}

int		ft_error3(int i, char *map1d)
{
	t_param	param;

	i = 0;
	while (map1d[i] != '\0')
		i++;
	if (i < 4)
		return (0);
	param.cv = map1d[i - 3];
	param.co = map1d[i - 2];
	param.cp = map1d[i - 1];
	if (param.cp == param.cv || param.cv == param.co || param.co == param.cp)
		return (0);
	return (1);
}
