/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_union.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/25 18:14:10 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/25 18:21:43 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_union(char *s1, char *s2)
{
	int i;
	int j;
	int check;
	int stop;

	i = 0;
	while (s1[i] != '\0')
	{
		check = 0;
		stop = 0;
		while (check < i && stop == 0)
		{
			if (s1[check] == s1[i])
				stop = 1;
			check++;
		}
		if (stop == 0)
			ft_putchar(s1[i]);
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		check = 0;
		stop = 0;
		while (check < j && stop == 0)
		{
			if (s2[check] == s2[j])
				stop = 1;
			check++;
		}
		check = 0;
		while (check < i && stop == 0)
		{
			if (s1[check] == s2[j])
				stop = 1;
			check++;
		}
		if (stop == 0)
			ft_putchar(s2[j]);
		j++;
	}
}

int		main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
}
/* ************************************************************************** */


