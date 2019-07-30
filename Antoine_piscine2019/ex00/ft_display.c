/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/24 16:37:19 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 23:41:16 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lib.h"

void	ft_display(char **map2d)
{
	t_pos	pos;

	pos.i = 0;
	pos.j = 0;
	if (ft_line(map2d) == 1)
	{
		while (map[pos.i][pos.j])
		{
			write(1, map2d[pos.i][pos.j], 1);
			pos.j++;
		}
	}
	else
	{
		while (map2d[pos.i] != '\0')
		{
			while (map2d[pos.i][pos.j] != '\0')
			{
				write(1, map2d[pos.i][pos.j], 1);
				pos.j++;
			}
			pos.j = 0;
			pos.i++;
		}
	}
}
