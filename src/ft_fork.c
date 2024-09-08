#include "../pipex.h"

int	ft_fork(int	i, t_cmd *cmd)
{	
	while (i < cmd->argc -1)
	{
		cmd->pid[i] = fork();
		cmd->temp_argv = cmd->cmd_argv[i + 1];
		if (cmd->pid[i] == -1)
		{
			perror("fork fail");
			return (EXIT_FAILURE);
		}	
		if (cmd->pid[i] == 0)
		{
			if (i % 2 == 0)
			{
				printf("qhqhqh");
				dup2(cmd->pipefd[1], STDIN_FILENO);
				close(cmd->pipefd[0]);
				close(cmd->pipefd[1]);
			}
			else
			{
				dup2(cmd->pipefd[0], STDOUT_FILENO);
				close(cmd->pipefd[1]);
				close(cmd->pipefd[0]);
			}
			find_cmd(cmd);
			
			exit (EXIT_SUCCESS);
		}
		if (cmd->pid[i] > 0)
			ft_father(cmd);
		i++;
	}
	return (EXIT_SUCCESS);
}