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
		{
			write(2, "bash: ", 7);
			write(2, argv[1], ft_strlen(argv[1]));
			write(2, ": ", 2);
			perror("");
			exit (EXIT_FAILURE);
		}
	}
	else if (i == 0 && cmd->index_here_doc == 1)
	{
		cmd->fd_infile = open("limiter.tmp", O_RDONLY);
		if (cmd->fd_infile < 0)
		{
			write(2, "bash: ", 7);
			write(2, argv[1], ft_strlen(argv[1]));
			write(2, ": ", 2);
			perror("");
			exit (EXIT_FAILURE);
		}
	}
}

void	ft_open_creat_outfile(t_cmd *cmd, char **argv, int i)
{
	if (i == cmd->pipelen)
	{
		if (cmd->index_here_doc == 1)
			cmd->fd_outfile = open(argv[cmd->last_argv], O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			cmd->fd_outfile = open(argv[cmd->last_argv], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (cmd->fd_outfile < 0)
		{
			write(2, "bash: ", 7);
			write(2, argv[cmd->last_argv], ft_strlen(argv[cmd->last_argv]));
			write(2, ": ", 2);
			perror("");
			exit (EXIT_FAILURE);
		}
	}
}
