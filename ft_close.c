/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:19:00 by chris             #+#    #+#             */
/*   Updated: 2023/02/07 16:08:51 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close(t_pipex *v)
{
	close(v->fd_in);
	close(v->fd_out);
	close(v->fd[0]);
	close(v->fd[1]);
}
