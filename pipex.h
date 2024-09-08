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
	char	**cmd_argv;
	char	**envp;
	char	**path;
	char	*buf;
	int		argc;
}			t_cmd;

int	find_path(t_cmd *cmd);

void	find_cmd(t_cmd *cmd);
void	ft_cpy_and_cat(char *buf, char *path, char *argv, int len);
void	ft_access(t_cmd *cmd);
void	ft_malloc(char **buf, int len);
void	ft_init_struct(int	argc, char **argv, char **envp, t_cmd *cmd);

#endif