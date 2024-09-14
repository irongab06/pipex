/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utile_open_close_file.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:56:35 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/13 15:59:38 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_open_infile(t_cmd *cmd, char **argv, int i)
{
	if (i == 0 && cmd->index_here_doc == 0)
	{
		cmd->fd_infile = open(argv[1], O_RDONLY);
		if (cmd->fd_infile < 0)
			ft_infile_error(cmd, argv);
	}
	else if (i == 0 && cmd->index_here_doc == 1)
	{
		cmd->fd_infile = open("limiter.tmp", O_RDONLY);
		if (cmd->fd_infile < 0)
			ft_infile_error(cmd, argv);
	}
}

void	ft_open_creat_outfile(t_cmd *cmd, char **argv, int i)
{
	int	flags_here_doc;
	int	flags;

	flags_here_doc = O_WRONLY | O_CREAT | O_APPEND;
	flags = O_WRONLY | O_TRUNC | O_CREAT;
	if (i == cmd->pipelen)
	{
		if (cmd->index_here_doc == 1)
			cmd->fd_outfile = open(argv[cmd->last_argv], flags_here_doc, 0644);
		else
			cmd->fd_outfile = open(argv[cmd->last_argv], flags, 0644);
		if (cmd->fd_outfile < 0)
			ft_outfile_error(cmd, argv);
	}
}
