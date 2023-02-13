/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 08:02:58 by chmassa           #+#    #+#             */
/*   Updated: 2022/10/24 08:25:43 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;
	int		s1len;

	i = 0;
	s1len = 0;
	while (s1[s1len])
		s1len++;
	str = malloc(sizeof(char) * s1len + 1);
	if (str == NULL)
		return (NULL);
	else
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
/*
int main(void)
{
	char	str[] = "Bonjour tout le monde !";
	char	*strcpy;

	strcpy = ft_strdup(str);

	printf("%s\n", strcpy);


	return (0);
}*/
