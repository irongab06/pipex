/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:07:20 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/09 11:09:58 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../pipex.h"

int	ft_fork(int	i, t_cmd *cmd)
{	
	int	fd;

	fd = open("text.txt", O_RDONLY);
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
			printf("i : %d\n", i);
			if (i % 2 == 0)
			{
				dup2(fd, STDOUT_FILENO);
				dup2(cmd->pipefd[1], STDOUT_FILENO);
				close(cmd->pipefd[0]);
				close(cmd->pipefd[1]);
			}
			else
			{
				
				dup2(cmd->pipefd[0], STDIN_FILENO);
				close(cmd->pipefd[1]);
				close(cmd->pipefd[0]);
			}
			
			find_cmd(cmd);
			
			exit (EXIT_SUCCESS);
		}
		// if (cmd->pid[i] > 0)
		// 	ft_father(cmd);
		i++;
	}
	return (EXIT_SUCCESS);
}