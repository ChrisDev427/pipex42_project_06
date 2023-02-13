/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:40:47 by chris             #+#    #+#             */
/*   Updated: 2023/02/08 17:54:31 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_variables(t_pipex *pipex, char **envp, int argc, char **av)
{
	pipex->fd_in = 0;
	pipex->fd_out = 0;
	pipex->ac = argc;
	pipex->envp = envp;
	pipex->cmd1 = set_cmd(av[2]);
	pipex->path_cmd1 = cmd_path(pipex->envp, pipex->cmd1);
	if (argc > 4)
	{
		pipex->cmd2 = set_cmd(av[3]);
		pipex->path_cmd2 = cmd_path(pipex->envp, pipex->cmd2);
	}
}
