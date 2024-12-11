/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:49:25 by tkeil             #+#    #+#             */
/*   Updated: 2024/12/11 15:49:42 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_set_in(char *argv, int *fd)
{
	int	in;

	in = open(argv, O_RDONLY);
	if (in == -1)
		ft_error(BAD_FD, STDOUT_FILENO);
	ft_dup2(in, STDIN_FILENO, fd);
}

void	ft_set_out(char *argv, int *fd)
{
	int	out;

	out = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (out == -1)
	{
		ft_close_pipe(fd);
		ft_error(BAD_FD, STDOUT_FILENO);
	}
	ft_dup2(out, STDOUT_FILENO, fd);
}

void	ft_close_pipe(int *fd)
{
	if (fd[0] >= 0)
		close(fd[0]);
	if (fd[1] >= 0)
		close(fd[1]);
}

void	ft_dup2(int s, int d, int *fd)
{
	if (dup2(s, d) == -1)
	{
		close(s);
		ft_close_pipe(fd);
		ft_error(BAD_DUP, STDOUT_FILENO);
	}
	close(s);
	ft_close_pipe(fd);
}

pid_t	ft_fork(int *fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		ft_close_pipe(fd);
		ft_error(BAD_DUP, STDOUT_FILENO);
	}
	return (pid);
}
