/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/25 20:01:33 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/25 21:29:09 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_wordcount(char *str)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			n++;
		i++;
	}
	n++;
	return (n);
}

int		ft_wordlen(int i, char *str)
{
	int		n;

	n = 0;
	while (str[i] != ' ' && str[i] != '\n' && str[i] != '\0' && str[i] != '\t')
	{
		n++;
		i++;
	}
	return (n);
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	**tab;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	tab = NULL;
	tab = malloc(sizeof(char *) * (ft_wordcount(str) + 1));
	if(tab == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			i++;
		if (!(tab[j] = malloc(sizeof(char *) * ft_wordlen(i, str))))
			return (NULL);
		k = i;
		while (i < (k + ft_wordlen(k, str)))
		{
			tab[j][l] = str[i];
			i++;
			l++;
		}
		tab[j][l] = '\0';
		l = 0;
		j++;
	}
	j++;
	tab[j] = NULL;
	return (tab);
}

int		main(int argc, char **argv)
{
	argc = 0;
	printf("%s", ft_split(argv[1]));
	return (0);
}
