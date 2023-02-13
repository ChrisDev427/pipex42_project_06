/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:00:12 by chmassa           #+#    #+#             */
/*   Updated: 2023/01/16 10:27:44 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
//********* Structure *********************************************************
typedef struct s_pipex
{
	int		fd_in;
	int		fd_out;
	int		fd[2];
	int		ac;
	char	*path_cmd1;
	char	**cmd1;
	char	*path_cmd2;
	char	**cmd2;
	char	**envp;
	pid_t	pid1;
	pid_t	pid2;
}				t_pipex;
//********* parsing functions *************************************************
char	**set_cmd(char *av);
char	*cmd_path(char **envp, char **av);
void	ft_open(t_pipex *v, char **av);
void	pipex(t_pipex *v);
void	ft_errors(char *tag, t_pipex *v);
void	ft_close(t_pipex *v);
void	init_variables(t_pipex *pipex, char **envp, int argc, char **argv);
#endif