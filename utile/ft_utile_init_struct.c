/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utile_init_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 08:19:49 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/13 18:26:18 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_init_struct(t_cmd *cmd, int argc)
{
	if (cmd->index_here_doc == 0)
	{
		cmd->pipelen = (argc - 4);
		cmd->shift = 2;

	}	
	else
	{
		debug("cmd ::::::");
		cmd->pipelen = (argc - 5);
		cmd->shift = 3;
	}
	cmd->fd_infile = -1;
	cmd->fd_outfile = -1;
	cmd->last_argv = (argc -1);
	cmd->cmd_path = NULL;
	cmd->path_buf = NULL;
	cmd->cmd_execve = NULL;
}

