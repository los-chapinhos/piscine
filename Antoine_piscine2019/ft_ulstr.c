/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ulstr.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/25 17:55:36 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/25 18:03:34 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ulstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			ft_putchar(str[i] - 32);
		else if (str[i] >= 'A' && str[i] <= 'Z')
			ft_putchar(str[i] + 32);
		else
			ft_putchar(str[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		ulstr(argv[1]);
	write(1, "\n", 1);
}
