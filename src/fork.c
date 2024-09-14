/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:06:14 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/13 18:01:58 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_fork(t_cmd *cmd, char **argv, char **envp)
{
	int	i;
	int	status;

	i = 0;
	while (i <= cmd->pipelen)
	{
		cmd->pid[i] = fork();
		if (cmd->pid[i] < 0)
			ft_fork_error(cmd);
		if (cmd->pid[i] == 0)
			ft_process_command(cmd, argv, envp, i);
		if (i > 0)
			ft_close_father(cmd, i);
		i++;
	}
	i = 0;
	while (i <= cmd->pipelen)
	{
		waitpid(cmd->pid[i], &status, 0);
		i++;
	}
	ft_free(cmd);
	return (WEXITSTATUS(status));
}

void	ft_process_command(t_cmd *cmd, char **argv, char **envp, int i)
{
	ft_open_infile(cmd, argv, i);
	ft_open_creat_outfile(cmd, argv, i);
	ft_dup(cmd, i);
	ft_close(cmd, i);
	ft_check_cmd(cmd, argv, i);
	ft_execve(cmd, argv, envp, i);
}
