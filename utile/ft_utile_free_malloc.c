/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utile_free_malloc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 08:40:33 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/13 15:12:33 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_free_pipe(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->pipefd != NULL)
	{
		while (i <= cmd->pipelen)
		{
			free(cmd->pipefd[i]);
			cmd->pipefd[i] = NULL;
			i++;
		}
		free(cmd->pipefd);
		cmd->pipefd = NULL;
	}
}

void	ft_free_cmd(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->cmd_execve != NULL)
	{
		while (cmd->cmd_execve[i] != NULL)
		{
			free(cmd->cmd_execve[i]);
			i++;
		}
		free(cmd->cmd_execve);
		cmd->cmd_execve = NULL;
		i = 0;
	}
	if (cmd->cmd_path != NULL)
	{
		while (cmd->cmd_path[i] != NULL)
		{
			free(cmd->cmd_path[i]);
			i++;
		}
		free(cmd->cmd_path);
		cmd->cmd_path = NULL;
	}
}

void	ft_malloc(t_cmd *cmd, int len)
{
	cmd->path_buf = malloc(sizeof(char *) * (len));
	if (cmd->path_buf == NULL)
	{
		ft_free(cmd);
		perror("malloc error");
		return ;
	}
}

void	ft_free(t_cmd *cmd)
{
	ft_free_pipe(cmd);
	if (cmd->pid != NULL)
	{
		free(cmd->pid);
		cmd->pid = NULL;
	}
	ft_free_cmd(cmd);
	if (cmd->path_buf != NULL)
	{
		free(cmd->path_buf);
		cmd->path_buf = NULL;
	}
}
