/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:37:56 by chmassa           #+#    #+#             */
/*   Updated: 2023/02/09 19:31:34 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child1(t_pipex *v)
{
	dup2(v->fd_in, STDIN_FILENO);
	if (v->ac == 5)
		dup2(v->fd[1], STDOUT_FILENO);
	else
		dup2(v->fd_out, STDOUT_FILENO);
	ft_close(v);
	if (execve(v->path_cmd1, v->cmd1, v->envp) == -1)
		ft_errors("exceve", v);
}

static void	child2(t_pipex *v)
{
	dup2(v->fd[0], STDIN_FILENO);
	dup2(v->fd_out, STDOUT_FILENO);
	ft_close(v);
	if (execve(v->path_cmd2, v->cmd2, v->envp) == -1)
		ft_errors("exceve", v);
}

void	pipex(t_pipex *v)
{
	if (pipe(v->fd) == -1)
		ft_errors("pipe", v);
	v->pid1 = fork();
	if (v->pid1 < 0)
		ft_errors("fork_pid1", v);
	if (v->pid1 == 0)
		child1(v);
	else
	{
		close(v->fd[1]);
		// waitpid(v->pid1, NULL, 0);
	}
	if (v->ac == 5)
	{
		v->pid2 = fork();
		if (v->pid2 < 0)
			ft_errors("fork_pid2", v);
		if (v->pid2 == 0)
			child2(v);
		else
		{
			ft_close(v);
			waitpid(v->pid2, NULL, 0);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	v;

	if (argc == 4 || argc == 5)
	{
		init_variables(&v, envp, argc, argv);
		ft_open(&v, argv);
		pipex(&v);
		free(v.path_cmd1);
		free_str_tab(v.cmd1);
		free(v.path_cmd2);
		free_str_tab(v.cmd2);
	}
	else
	{
		ft_putstr_fd("Invalid number of arguments\n", 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}
