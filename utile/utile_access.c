#include "../pipex.h"

void	ft_access(t_cmd *cmd)
{
	int i;
	int len;
	
	len = 0;
	i = 0;
	while (cmd->path[i] != NULL)
	{
		len = ft_strlen(cmd->path[i]) + ft_strlen(cmd->temp_argv) + 2;
		ft_malloc(&cmd->buf, len);
		ft_cpy_and_cat(cmd->buf, cmd->path[i], cmd->temp_argv, len);
		if (access(cmd->buf, X_OK) == 0)
		{
			char	*execv[2];

			execv[0] = cmd->temp_argv;
			execv[1] = NULL;
			execve(cmd->buf, execv, cmd->envp);
			free(cmd->buf);
			free(execv[0]);
			free(execv[1]);
			break ;
		}
		else
			free(cmd->buf);
		i++;
	}
}