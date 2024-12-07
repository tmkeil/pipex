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

# define BAD_FD 9
# define BAD_PIPE 32
# define BAD_UNDEFINED 0
# define BAD_ALLOCATION 12

# include "libft.h"
# include <sys/wait.h>
# include <string.h>

void	ft_error(int errno);
char    *ft_getpath(char *cmd, char **envp);

#endif
