/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:44:14 by tkeil             #+#    #+#             */
/*   Updated: 2024/12/07 19:13:46 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(int errnum, int fd)
{
    if (errnum == BAD_PIPE)
        ft_putendl_fd("couldn't pipe", fd);
    else if (errnum == BAD_FORK)
        ft_putendl_fd("couldn't fork", fd);
    else if (errnum == BAD_FD)
        ft_putendl_fd("couldn't open", fd);
    else if (errnum == BAD_ALLOCATION)
        ft_putendl_fd("couldn't allocate", fd);
    else if (errnum == BAD_EXECUTE)
        ft_putendl_fd("couldn't execute", fd);
    else if (errnum == BAD_DUP)
        ft_putendl_fd("couldn't duplicate", fd);
    perror("Error");
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

static char	*ft_check_paths(char *env, char *cmd)
{
	int		i;
	char	*path;
	char	*full;

	i = 0;
	path = NULL;
	full = NULL;
	while (env[i])
    {
        path = ft_strjoin(env[i], "/");
        full = ft_strjoin(path, cmd);
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

char    *ft_getpath(char *cmd, char **envp)
{
    char    **env;

    if (!envp || !*envp)
        return (NULL);
    while (*envp)
    {
        if (ft_strnstr(envp++, "PATH=", 5))
            break ;
    }
    env = ft_split(envp + 5, ' ');
    if (!env || !*env)
        return (NULL);
	return (ft_check_paths(env, cmd));
}
