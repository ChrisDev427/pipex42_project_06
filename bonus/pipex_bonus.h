/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:00:12 by chmassa           #+#    #+#             */
/*   Updated: 2023/02/09 11:11:53 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# define HEREDOC_INPUT 1
# define FILE_INPUT 0
# include "../libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
//********* Structure *********************************************************
typedef struct s_pipex
{
	int		i;
	int		input;
	int		av_cmd;
	int		fd_in;
	int		fd_out;
	int		ac;
	int		fd[2];
	int		fd_tmp;
	int		nbr_pipe;
	int		nbr_process;
	char	*path_cmd;
	char	**cmd;
	char	**envp;
	pid_t	pid1;
}				t_pipex;
//********* parsing functions *************************************************
void	ft_open_bonus(t_pipex *v, char **av);
void	ft_errors_bonus(char *tag, t_pipex *v);
void	pipex_bonus(char **av, t_pipex *v);
char	**set_cmd_bonus(char *av);
char	*cmd_path_bonus(char **envp, char **av);
void	heredoc_bonus(t_pipex *v, char **argv);
void	ft_process_bonus(t_pipex *v);
#endif