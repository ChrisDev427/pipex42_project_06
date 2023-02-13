/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmd_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:13:48 by chmassa           #+#    #+#             */
/*   Updated: 2023/02/09 09:43:10 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*cut_cmd(char *s)
{
	char	*cutted;

	cutted = ft_substr(s, ft_str_rchr(s, '/') + 1, ft_strlen(s)
			- (ft_str_rchr(s, '/') + 1));
	return (cutted);
}

char	**set_cmd_bonus(char *av)
{
	char	**cmd;
	int		check;

	check = 0;
	if (!av)
		return (NULL);
	if (ft_strrchr(av, '/'))
	{
		av = cut_cmd(av);
		check ++;
	}
	cmd = ft_split(av, ' ');
	if (!cmd)
		return (NULL);
	if (check != 0)
		free (av);
	return (cmd);
}
