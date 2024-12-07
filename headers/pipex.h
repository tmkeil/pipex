/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:40:24 by tkeil             #+#    #+#             */
/*   Updated: 2024/12/07 14:45:17 by tkeil            ###   ########.fr       */
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

void	ft_clr(char ***ptr);
void	ft_error(int errno, int fd);
void	ft_execute(int std_out, char *argv, char **envp);

// bonus
pid_t   ft_fork(int *fd);
void    ft_close_pipe(int *fd);
void    ft_set_in(char *argv, int *fd);
void    ft_dup2(int s, int d, int *fd);
void    ft_set_out(char *argv, int *fd);

#endif
