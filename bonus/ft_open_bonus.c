/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:53:49 by chmassa           #+#    #+#             */
/*   Updated: 2023/02/08 18:17:08 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	wrong_file(char *av)
{
	perror(av);
	exit (EXIT_FAILURE);
}

void	ft_open_bonus(t_pipex *v, char **av)
{
	int	i;

	i = 0;
	if (v->input == 0)
	{
		v->fd_in = open(av[1], O_RDONLY);
		if (v->fd_in < 0)
			wrong_file(av[1]);
	}
	while (av[i])
	{
		if (av[i + 1] == NULL)
		{
			if (ft_strcmp(av[1], "here_doc") == 0)
				v->fd_out = open(av[i], O_RDWR | O_CREAT | O_APPEND, 0666);
			else
				v->fd_out = open(av[i], O_RDWR | O_CREAT | O_TRUNC, 0666);
			if (v->fd_out < 0)
				wrong_file(av[i]);
		}
		i++;
	}
}
