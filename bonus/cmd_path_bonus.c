/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:27:55 by chmassa           #+#    #+#             */
/*   Updated: 2023/02/09 10:56:57 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	**paths_retrieve(char **envp)
{
	char	**paths;
	char	*path_line;
	int		i;

	i = -1;
	paths = NULL;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			path_line = ft_strdup(ft_strchr(envp[i], '/'));
			paths = ft_split(path_line, ':');
			free(path_line);
		}
	}
	if (!paths)
	{
		ft_putstr_fd("Error: path not found\n", 2);
		exit (EXIT_FAILURE);
	}
	i = -1;
	while (paths[++i])
		paths[i] = ft_strjoin(paths[i], "/");
	return (paths);
}

static void	add_arg(char **paths, char **cmd)
{
	int	i;

	i = -1;
	while (paths[++i])
		paths[i] = ft_strjoin(paths[i], cmd[0]);
}

static int	ft_access(char **paths)
{
	int	i;
	int	r;

	i = -1;
	r = -1;
	while (paths[++i])
	{
		if (access(paths[i], F_OK) == 0)
			r = i;
	}
	return (r);
}

char	*cmd_path_bonus(char **envp, char **cmd)
{
	char	**paths;
	char	*cmd_path;
	int		access_return;

	if (!envp)
		return (NULL);
	paths = paths_retrieve(envp);
	add_arg(paths, cmd);
	access_return = ft_access(paths);
	if (access_return == -1)
	{
		write (2, "pipex: ", 7);
		ft_putstr_fd(cmd[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		free_str_tab(paths);
		exit (EXIT_FAILURE);
	}
	cmd_path = ft_strdup(paths[access_return]);
	free_str_tab(paths);
	return (cmd_path);
}
