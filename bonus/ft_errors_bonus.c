/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:59:45 by chris             #+#    #+#             */
/*   Updated: 2023/02/09 10:57:57 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_errors_bonus(char *tag, t_pipex *v)
{
	perror(tag);
	v = NULL;
	free(v->path_cmd);
	free_str_tab(v->cmd);
	exit(EXIT_FAILURE);
}
