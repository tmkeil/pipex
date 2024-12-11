/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:44:14 by tkeil             #+#    #+#             */
/*   Updated: 2024/12/11 15:50:26 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(int errnum, int fd)
{
	if (errnum == BAD_PIPE)
		ft_putendl_fd("Error: couldn't pipe", fd);
	else if (errnum == BAD_FORK)
		ft_putendl_fd("Error: couldn't fork", fd);
	else if (errnum == BAD_FD)
		ft_putendl_fd("Error: couldn't open", fd);
	else if (errnum == BAD_ALLOCATION)
		ft_putendl_fd("Error: couldn't allocate", fd);
	else if (errnum == BAD_EXECUTE)
		ft_putendl_fd("Error: couldn't execute", fd);
	else if (errnum == BAD_DUP)
		ft_putendl_fd("Error: couldn't duplicate", fd);
	else if (errnum == BAD_WAITPID)
		ft_putendl_fd("Error: waitpid error", fd);
	exit(errnum);
}

void	ft_clr(char ***ptr)
{
	int	i;

	if (!ptr || !*ptr || !**ptr)
		return ;
	i = 0;
	while ((*ptr)[i])
		free((*ptr)[i++]);
	free(*ptr);
	*ptr = NULL;
}

static char	*ft_check_paths(char **env, char *cmd)
{
	int		i;
	char	*path;
	char	*full;

	i = 0;
	path = NULL;
	full = NULL;
	while (env[i])
	{
		printf("env[%i] = %s\n", i, env[i]);
		path = ft_strjoin(env[i], "/");
		full = ft_strjoin(path, cmd);
		printf("wird gecheckt: %s\n", full);
		free(path);
		if (!full)
			return (ft_clr(&env), NULL);
		if (access(full, X_OK) == 0)
			return (ft_clr(&env), full);
		free(full);
		i++;
	}
	return (ft_clr(&env), NULL);
}

char	*ft_getpath(char *cmd, char **envp)
{
	char	**env;

	if (!envp || !*envp)
		return (NULL);
	while (*envp)
	{
		if (ft_strnstr(*envp, "PATH=", 5))
			break ;
		envp++;
	}
	env = ft_split(*envp + 5, ':');
	if (!env || !*env)
		return (NULL);
	return (ft_check_paths(env, cmd));
}

void	ft_execute(int std_out, char *argv, char **envp)
{
	char	*path;
	char	**cmds;

	cmds = ft_split(argv, ' ');
	if (!cmds)
		ft_error(BAD_ALLOCATION, std_out);
	path = ft_getpath(cmds[0], envp);
	if (!path || execve(path, cmds, envp) == -1)
	{
		free(path);
		ft_clr(&cmds);
		ft_error(BAD_EXECUTE, std_out);
	}
}
