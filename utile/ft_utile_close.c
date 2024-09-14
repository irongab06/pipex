/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utile_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:07:14 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/13 18:02:52 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_close(t_cmd *cmd, int i)
{
	if (i == 0)
		ft_close_first_pipe(cmd, i);
	else if (i == cmd->pipelen)
		ft_close_last_pipe(cmd, i);
	else
		ft_close_middle_pipe(cmd, i);
}

void	ft_close_first_pipe(t_cmd *cmd, int i)
{
	close(cmd->pipefd[i][0]);
	close(cmd->fd_infile);
	close(cmd->pipefd[i][1]);
	if (cmd->index_here_doc == 1)
		unlink("limiter.tmp");
}

void	ft_close_middle_pipe(t_cmd *cmd, int i)
{
	close(cmd->pipefd[i - 1][1]);
	close(cmd->pipefd[i][0]);
	close(cmd->pipefd[i - 1][0]);
	close(cmd->pipefd[i][1]);
}

void	ft_close_last_pipe(t_cmd *cmd, int i)
{
	close(cmd->pipefd[i - 1][1]);
	close(cmd->pipefd[i - 1][0]);
	close(cmd->fd_outfile);
}

void	ft_close_father(t_cmd *cmd, int i)
{
	close(cmd->pipefd[i - 1][0]);
	close(cmd->pipefd[i - 1][1]);
}
