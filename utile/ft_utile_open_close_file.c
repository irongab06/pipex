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
	//printf("i %d\n", i);
	if (i == 0)
	{
		cmd->fd_infile = open(argv[1], O_RDONLY);
		//printf("fd %d\n", cmd->fd_infile);
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
		cmd->fd_outfile = open(argv[cmd->last_argv], O_WRONLY | O_TRUNC | O_CREAT, 0777);
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
