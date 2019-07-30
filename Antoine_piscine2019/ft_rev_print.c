/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/16 14:03:48 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/16 16:13:07 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i],1);
		i++;
	}
}

void	ft_rev_print(char *str)
{
	int i;
	int a;
	int len;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		while (i < (len / 2))
		{
			a = str[i];
			str[i] = str[len - 1 - i];
			str[len - 1 -i] = a;
			i++;
		}
		i++;
	}
	str[i] = '\0';
	ft_putstr(str);
}

int	main(int argc, char **argv)
{
	ft_rev_print(argv[1]);
	return (0);
}
