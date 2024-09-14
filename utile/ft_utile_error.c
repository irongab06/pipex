/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utile_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 08:56:34 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/13 15:05:56 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_init_and_error(t_cmd *cmd, int i)
{
	if (i == 0)
		i = ft_init_pipefd(cmd);
	if (i == 0)
		i = ft_init_pid(cmd);
	return (i);
}

void	ft_fork_error(t_cmd *cmd)
{
	perror("fork fail");
	ft_free(cmd);
	exit (EXIT_FAILURE);
}

void	ft_infile_error(t_cmd *cmd, char **argv)
{
	if (cmd->index_here_doc == 0)
	{
		write(2, "bash: ", 7);
		write(2, argv[1], ft_strlen(argv[1]));
		write(2, ": ", 2);
	}
	else
	{
		write(2, "bash: ", 7);
		write(2, "limiter.tmp", 11);
		write(2, ": ", 2);
	}
	perror("");
	ft_free(cmd);
	exit (EXIT_FAILURE);
}

void	ft_outfile_error(t_cmd *cmd, char **argv)
{
	write(2, "bash: ", 7);
	write(2, argv[cmd->last_argv], ft_strlen(argv[cmd->last_argv]));
	write(2, ": ", 2);
	perror("");
	ft_free(cmd);
	exit (EXIT_FAILURE);
}
