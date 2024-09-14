/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 08:16:24 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/13 18:03:11 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_cmd
{
	pid_t	*pid;
	int		pipelen;
	int		**pipefd;
	int		fd_infile;
	int		fd_outfile;
	int		index_here_doc;
	int		last_argv;
	int		shift;
	char	**cmd_path;
	char	**cmd_execve;
	char	*path_buf;
}			t_cmd;

void 	debug(char *debug);
void	find_path(t_cmd *cmd, char **envp);
void	ft_init_struct(t_cmd *cmd, int argc);
void	ft_free_pipe(t_cmd *cmd);
int		ft_fork(t_cmd *cmd, char **argv, char **envp);
void	ft_open_infile(t_cmd *cmd, char **argv, int i);
void	ft_open_creat_outfile(t_cmd *cmd, char **argv, int i);
void	ft_dup(t_cmd *cmd, int i);
void	ft_dup_pipe_first_cmd(t_cmd *cmd, int i);
void	ft_dup_pipe_middle_cmd(t_cmd *cmd, int i);
void	ft_dup_pipe_last_cmd(t_cmd *cmd, int i);
void	ft_close(t_cmd *cmd, int i);
void	ft_close_first_pipe(t_cmd *cmd, int i);
void	ft_close_middle_pipe(t_cmd *cmd, int i);
void	ft_close_last_pipe(t_cmd *cmd, int i);
void	ft_init_buf(t_cmd *cmd, char **argv, int i, int j);
void	ft_check_cmd(t_cmd *cmd, char **argv, int i);
void	ft_cpy_and_cat(char *buf, char *path, char *argv, int len);
void	ft_execve(t_cmd *cmd, char **argv, char **envp, int i);
void	ft_malloc(char **buf, int len);
void	ft_close_father(t_cmd *cmd, int i);
void	here_doc(t_cmd *cmd, char **argv);
void	check_here_doc(t_cmd *cmd, char **argv);

int	ft_init_pipefd(t_cmd *cmd);
int	ft_active_pipe(t_cmd *cmd);
int	ft_init_pid(t_cmd *cmd);
int	ft_init_and_error(t_cmd *cmd, int i);
int	ft_len_argv(char *argv);

#endif