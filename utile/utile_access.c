#include "../pipex.h"

void	ft_access(t_cmd *cmd)
{
	int i;
	int	j;
	int len;

	len = 0;
	i = 0;
	j = 1;
	while (cmd->path[i] != NULL)
	{
		len = ft_strlen(cmd->path[i]) + ft_strlen(cmd->cmd_argv[j]) + 2;
		ft_malloc(&cmd->buf, len);
		ft_cpy_and_cat(cmd->buf, cmd->path[i], cmd->cmd_argv[j], len);
		if (access(cmd->buf, X_OK) == 0)
		{
			execve(cmd->buf, &cmd->cmd_argv[1], cmd->envp);
			free(cmd->buf);
			break ;
		}
		else
			free(cmd->buf);
		i++;
	}
}