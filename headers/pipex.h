/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:43:55 by tkeil             #+#    #+#             */
/*   Updated: 2024/12/07 19:13:49 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define BAD_PIPE 0
# define BAD_FORK 1
# define BAD_FD 2
# define BAD_ALLOCATION 3
# define BAD_EXECUTE 4
# define BAD_DUP 5


# include "libft.h"
# include <sys/wait.h>
# include <string.h>

void	ft_clr(char ***ptr);
void	ft_error(int errnum, int fd);
char    *ft_getpath(char *cmd, char **envp);
void	ft_execute(int std_out, char *argv, char **envp);

#endif
