/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:59:09 by chmassa           #+#    #+#             */
/*   Updated: 2023/02/05 07:43:51 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	heredoc_bonus(t_pipex *v, char **argv)
{
	char	*s;
	char	*stmp;

	if (pipe(v->fd) == -1)
		return ;
	while (1)
	{
		write(1, "> ", 2);
		s = get_next_line(0);
		stmp = ft_strtrim(s, "\n");
		if (!ft_strcmp(argv[2], stmp))
		{
			free(s);
			free(stmp);
			break ;
		}
		if (v->ac > 3)
			ft_putstr_fd(s, v->fd[1]);
		free(s);
		free(stmp);
	}
	v->fd_tmp = v->fd[0];
	close(v->fd[1]);
}
