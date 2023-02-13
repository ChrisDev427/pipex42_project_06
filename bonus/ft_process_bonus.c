/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:22:55 by chmassa           #+#    #+#             */
/*   Updated: 2023/02/08 18:16:49 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	first_process(t_pipex *v)
{
	if (v->input == FILE_INPUT)
		dup2(v->fd_in, STDIN_FILENO);
	else if (v->input == HEREDOC_INPUT)
		dup2(v->fd_tmp, STDIN_FILENO);
	dup2(v->fd[1], STDOUT_FILENO);
	close(v->fd[0]);
	close(v->fd[1]);
	if (execve(v->path_cmd, v->cmd, v->envp) == -1)
		ft_errors_bonus("execve", v);
}

static void	inter_process(t_pipex *v)
{
	dup2(v->fd_tmp, STDIN_FILENO);
	dup2(v->fd[1], STDOUT_FILENO);
	close(v->fd_tmp);
	close(v->fd[1]);
	close(v->fd[0]);
	if (execve(v->path_cmd, v->cmd, v->envp) == -1)
		ft_errors_bonus("execve", v);
}

static void	last_process(t_pipex *v)
{
	dup2(v->fd_tmp, STDIN_FILENO);
	dup2(v->fd_out, STDOUT_FILENO);
	close(v->fd_tmp);
	close(v->fd[0]);
	close(v->fd[1]);
	if (execve(v->path_cmd, v->cmd, v->envp) == -1)
		ft_errors_bonus("execve", v);
}

void	ft_process_bonus(t_pipex *v)
{
	if (v->nbr_process == 1 && v->input == FILE_INPUT)
		v->fd_tmp = v->fd_in;
	if (v->i == 0 && v-> nbr_process != 1)
		first_process(v);
	else if (v->i > 0 && v->i < v->nbr_process -1)
		inter_process(v);
	else if (v->i == v->nbr_process -1)
		last_process(v);
}
