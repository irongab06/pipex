/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:08:50 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/09 09:08:55 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PIPEX_H
#define PIPEX_H

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct	s_cmd
{
	pid_t	*pid;
	char	**cmd_argv;
	char	**envp;
	char	**path;
	char	*temp_argv;
	char	*buf;
	int		argc;
	int		pipefd[2];
}			t_cmd;

int	find_path(t_cmd *cmd);
int	ft_fork(int	i, t_cmd *cmd);

void	find_cmd(t_cmd *cmd);
void	ft_cpy_and_cat(char *buf, char *path, char *argv, int len);
void	ft_access(t_cmd *cmd);
void	ft_malloc(char **buf, int len);
void	ft_init_struct(int	argc, char **argv, char **envp, t_cmd *cmd);
void	ft_father(t_cmd *cmd);
void	ft_malloc_pid(t_cmd *cmd);

#endif