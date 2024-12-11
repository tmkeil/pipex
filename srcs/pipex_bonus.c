/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:24:19 by tkeil             #+#    #+#             */
/*   Updated: 2024/12/11 16:28:36 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_child(char **envp, char *argv, int *fd, int *read)
{
	pid_t	pid;

	pid = ft_fork(fd);
	if (pid == 0)
	{
		if (*read != -1)
			ft_dup2(*read, STDIN_FILENO, fd);
		ft_dup2(fd[1], STDOUT_FILENO, fd);
		ft_execute(STDOUT_FILENO, argv, envp);
	}
	if (*read != -1)
		close(*read);
	else
		*read = fd[0];
	ft_close_pipe(fd);
	if (waitpid(pid, NULL, 0) == -1)
	{
		ft_close_pipe(fd);
		ft_error(BAD_WAITPID, STDOUT_FILENO);
	}
}

static void	ft_create_pipe(int *fd, int *read, char *argv, char **envp)
{
	if (pipe(fd) == -1)
		ft_error(BAD_PIPE, STDOUT_FILENO);
	ft_child(envp, argv, fd, read);
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	read;
	int	fd[2];

	if (argc < 5 || argc > 10 || !*argv[1])
		return (1);
	ft_set_in(argv[1], fd);
	i = 2;
	read = -1;
	while (i < argc - 2)
		ft_create_pipe(fd, &read, argv[i++], envp);
	ft_set_out(argv[argc - 1], fd);
	ft_dup2(read, STDIN_FILENO, fd);
	ft_close_pipe(fd);
	ft_execute(STDOUT_FILENO, argv[argc - 2], envp);
	return (0);
}
