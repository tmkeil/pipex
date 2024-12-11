/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:50:15 by tkeil             #+#    #+#             */
/*   Updated: 2024/12/11 15:50:28 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_waitpd(pid_t pid, int *status, int option, int *fd)
{
	if (waitpid(pid, status, option) == -1)
	{
		ft_close_pipe(fd);
		ft_error(BAD_WAITPID, STDOUT_FILENO);
	}
}
