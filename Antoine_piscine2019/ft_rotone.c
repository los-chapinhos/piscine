/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_rotone.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/21 18:45:28 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/21 18:51:36 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rotone(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] <= 'y' && str[i] >= 'a') || (str[i] <= 'Y' && str[i] >= 'A'))
			ft_putchar(str[i] + 1);
		else if (str[i] == 'z' || str[i] == 'Z')
			ft_putchar(str[i] - 25);
		else 
			ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rotone(argv[1]);
	ft_putchar('\n');
}

