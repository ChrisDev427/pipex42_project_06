/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:59:45 by chris             #+#    #+#             */
/*   Updated: 2023/02/07 16:09:00 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_errors(char *tag, t_pipex *v)
{
	perror(tag);
	free(v->path_cmd1);
	free_str_tab(v->cmd1);
	free(v->path_cmd2);
	free_str_tab(v->cmd2);
	exit(EXIT_FAILURE);
}
