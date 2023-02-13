/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:37:56 by chmassa           #+#    #+#             */
/*   Updated: 2023/02/09 11:03:59 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	init_var(t_pipex *pipex, char **envp, int argc)
{
	pipex->i = 0;
	pipex->input = FILE_INPUT;
	pipex->fd_in = 0;
	pipex->fd_out = 0;
	pipex->fd_tmp = 0;
	pipex->nbr_pipe = argc -4;
	pipex->nbr_process = argc -3;
	pipex->av_cmd = 2;
	pipex->ac = argc;
	pipex->envp = envp;
}

void	pipex_bonus(char **av, t_pipex *v)
{
	while (v->i < v->nbr_process)
	{
		v->cmd = set_cmd_bonus(av[v->av_cmd++]);
		v->path_cmd = cmd_path_bonus(v->envp, v->cmd);
		if (pipe(v->fd) == -1)
			ft_errors_bonus("pipe", v);
		v->pid1 = fork();
		if (v->pid1 < 0)
			ft_errors_bonus("pipe", v);
		if (v->pid1 == 0)
			ft_process_bonus(v);
		else
			if (v->fd_tmp != 0 && v->input == FILE_INPUT)
				close(v->fd_tmp);
		v->fd_tmp = v->fd[0];
		close(v->fd[1]);
		waitpid(v->pid1, NULL, 0);
		v->i++;
		free(v->path_cmd);
		free_str_tab(v->cmd);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	v;

	if (argc == 3 && ft_strcmp(argv[1], "here_doc") == 0)
		heredoc_bonus(&v, argv);
	else if (argc > 3)
	{
		init_var(&v, envp, argc);
		if (ft_strcmp(argv[1], "here_doc") == 0)
		{
			v.nbr_pipe = argc -5;
			v.nbr_process = argc -4;
			v.av_cmd = 3;
			v.input = HEREDOC_INPUT;
			heredoc_bonus(&v, argv);
		}
		ft_open_bonus(&v, argv);
		pipex_bonus(argv, &v);
	}
	else
	{
		ft_printf("Error, pipex needs at least 4 args.\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
