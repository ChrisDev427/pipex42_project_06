/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:53:49 by chmassa           #+#    #+#             */
/*   Updated: 2023/02/08 11:43:27 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_open(t_pipex *v, char **av)
{
	int	i;

	i = 0;
	v->fd_in = open(av[1], O_RDONLY);
	if (v->fd_in < 0)
	{
		perror(av[1]);
		exit (EXIT_FAILURE);
	}
	while (av[i])
	{
		if (av[i + 1] == NULL)
		{
			v->fd_out = open(av[i], O_RDWR | O_CREAT | O_TRUNC, 0666);
			if (v->fd_out < 0)
			{
				perror(av[i]);
				exit (EXIT_FAILURE);
			}
		}
		i++;
	}
}
