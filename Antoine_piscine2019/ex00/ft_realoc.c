/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/24 20:43:38 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 21:23:56 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lib.h"

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src, int oct, int len)
{
	int i;
	int dest_len;

	dest_len = len - oct;
	i = 0;
	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

char	*ft_realoc(char *old, int len, char *buff, int oct)
{
	char *new;

	new = (char *)malloc(sizeof(char) * (len + 1));
	ft_strcpy(new, old);
	ft_strcat(new, buff, oct, len);
	free(old);
	return (new);
}
