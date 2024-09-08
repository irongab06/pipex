#include "../pipex.h"

void	ft_init_struct(int	argc, char **argv, char **envp, t_cmd *cmd)
{
	cmd->cmd_argv = argv;
	cmd->envp = envp;
	cmd->argc = argc;
	cmd->path = NULL;
	cmd->temp_argv = NULL;
}