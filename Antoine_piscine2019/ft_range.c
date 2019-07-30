/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_range.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/25 15:34:14 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/25 17:32:28 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int start, int end)
{
	int i;
	int stop;
	int *tab;

	i = 0;
	if (start > end)
	{
		if (!(tab = malloc(sizeof(int*) * (start - end))))
			return (0);
	}
	else
	{
		if (!(tab = malloc(sizeof(int*) * (end - start))))
			return (0);
	}
	stop = 0;
	while (start <= end)
	{
		tab[i] = start;
		printf("%d", tab[i]);
		start++;
		i++;
		stop = 1;
	}
	while (start >= end && stop == 0)
	{
		tab[i] = start;
		printf("%d", tab[i]);
		start--;
		i++;
	}
	return (tab);
}

int		main()
{
	int		start = 10;
	int		end = 20;
	ft_range(start, end);
}
