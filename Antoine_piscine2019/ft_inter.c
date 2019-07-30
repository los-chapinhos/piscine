/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_inter.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/25 14:07:20 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/25 17:55:20 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_check_str(char c, char *tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	ft_inter(char *s1, char *s2)
{
	int i;
	int j;
	int k;
	char tab[256];

	i = 0;
	k = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j] && ft_check_str(s1[i], tab) == 1)
			{
				ft_putchar(s1[i]);
				tab[k] = s1[i];
				k++;
			}
			j++;
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 3)
	{
		ft_inter(av[1], av[2]);
	}
	ft_putchar('\n');
	return (0);
}
