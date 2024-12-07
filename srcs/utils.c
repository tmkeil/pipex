/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:43:03 by tkeil             #+#    #+#             */
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2024/12/07 20:45:16 by tkeil            ###   ########.fr       */
=======
/*   Updated: 2024/12/07 21:01:09 by tkeil            ###   ########.fr       */
>>>>>>> f3350e0 (mend)
=======
=======
>>>>>>> 2938c21 (mend)
/*   Updated: 2024/12/07 21:01:09 by tkeil            ###   ########.fr       */
=======
/*   Updated: 2024/12/07 19:55:49 by tkeil            ###   ########.fr       */
=======
/*   Updated: 2024/12/06 22:45:17 by tkeil            ###   ########.fr       */
>>>>>>> 2b565b7 (almost all)
>>>>>>> 48ac8b8 (bonus try and relocated functions)
<<<<<<< HEAD
>>>>>>> f7bbedc (mend)
=======
=======
/*   Updated: 2024/12/07 20:45:16 by tkeil            ###   ########.fr       */
>>>>>>> 2316ed0 (fixed)
>>>>>>> 2938c21 (mend)
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(int errno, int fd)
{
	ft_putendl_fd(strerror(errno), fd);
	exit(errno);
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
