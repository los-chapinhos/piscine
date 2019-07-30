/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/22 15:03:08 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/25 09:30:59 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lib.h"

char	*ft_map1d_generator_v2(int size, int rd, char *av, char *map1d)
{
	int		dict;
	int		ret;
	int		i;
	int		cpt;
	char	buff[BUFF_SIZE + 1000000];

	dict = open(av, O_RDONLY);
	i = 0;
	cpt = 0;
	if (!(map1d = malloc(sizeof(char) * (size + 1))))
		return (0);
	if (dict == -1)
		return (0);
	while ((ret = read(dict, buff, BUFF_SIZE) && rd >= 0))
	{
		buff[ret] = '\0';
		map1d[i] = buff[0];
		i++;
		rd--;
	}
	map1d[i] = '\0';
	return (map1d);
}

int		ft_argument(int ac, char **av)
{
	int		i;
	int		j;
	int		size;
	char	*map1d;
	char	**map2d;

	i = 1;
	j = 0;
	while (i < ac)
	{
		size = ft_map_size(av[i]);
		map1d = ft_map1d_generator(size, av[i], map1d);
		map2d = ft_map2d_generator(map1d, map2d);
		map1d = ft_param(map1d);
		if (ft_error1(i, map2d) == 0 || ft_error2(i, j, map1d, map2d) == 0
				|| ft_error3(i, map1d))
		{
			write(1, "map error\n", 10);
			return (0);
		}
		map2d = ft_pre_resolve(map1d, map2d);
		ft_display(map2d);
		i++;
	}
	return (0);
}

int		ft_argument_v2(int ac, char *map1d)
{
	int		i;
	int		j;
	int		size;
	char	**map2d;

	i = 1;
	j = 0;
	while (i < ac)
	{
		size = ft_strlen_v2(map1d);
		map2d = ft_map2d_generator(map1d, map2d);
		map1d = ft_param(map1d);
		if (ft_error1(i, map2d) == 0 || ft_error2(i, j, map1d, map2d) == 0
				|| ft_error3(i, map1d))
		{
			write(1, "map error\n", 10);
			return (0);
		}
		map2d = ft_pre_resolve(map1d, map2d);
		ft_display(map2d);
		i++;
		if (ac > 2)
			write(1, "\n", 1);
	}
	return (0);
}

int		ft_standard(void)
{
	int		ret;
	int		len;
	char	*str;
	char	*buff;

	if (!(str = malloc(sizeof(char))))
		return (0);
	len = 0;
	ret = 1;
	buff = malloc(sizeof(char) * (BUFF_SIZE + 1));
	while (ret != 0)
	{
		ret = read(0, buff, BUFF_SIZE);
		buff[ret] = '\0';
		len = len + ret;
		if (ret != 0)
			str = ft_realoc(str, len, buff, ret);
	}
	str[len] = '\0';
	free(buff);
	ft_argument_v2(2, str);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac > 1)
		ft_argument(ac, av);
	if (ac == 1)
		ft_standard();
}
