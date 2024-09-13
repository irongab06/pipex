/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utile_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:30:47 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/13 15:50:26 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_dup(t_cmd *cmd, int i)
{
	if (i == 0)
		ft_dup_pipe_first_cmd(cmd, i);
	else if (i == cmd->pipelen)
		ft_dup_pipe_last_cmd(cmd, i);
	else
		ft_dup_pipe_middle_cmd(cmd, i);
}

void	ft_dup_pipe_first_cmd(t_cmd *cmd, int i)
{
	if (dup2(cmd->fd_infile, STDIN_FILENO) == -1)
	{
		perror("dup2 failed");
		exit (EXIT_FAILURE);
	}
	if (dup2(cmd->pipefd[i][1], STDOUT_FILENO) == -1)
	{
		perror("dup2 failed");
		exit (EXIT_FAILURE);
	}

	//-------

	// close(cmd->pipefd[i][0]);
	// close(cmd->fd_infile);
	// close(cmd->pipefd[i][1]);
}

void	ft_dup_pipe_middle_cmd(t_cmd *cmd, int i)
{
	dup2(cmd->pipefd[i - 1][0], STDIN_FILENO);
	dup2(cmd->pipefd[i][1], STDOUT_FILENO);

	//--------

	// close(cmd->pipefd[i - 1][1]);
	// close(cmd->pipefd[i][0]);
	// close(cmd->pipefd[i - 1][0]);
	// close(cmd->pipefd[i][1]);
}

void	ft_dup_pipe_last_cmd(t_cmd *cmd, int i)
{
	dup2(cmd->pipefd[i - 1][0], STDIN_FILENO);
	dup2(cmd->fd_outfile, STDOUT_FILENO);

	//-------
	
	// close(cmd->pipefd[i - 1][1]);
	// close(cmd->pipefd[i - 1][0]);
	// close(cmd->fd_outfile);
}