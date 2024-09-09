/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:07:30 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/09 09:24:32 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../pipex.h"

int	find_path(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->envp[i] != NULL)
	{
		if (ft_strncmp(cmd->envp[i], "PATH=", 5) == 0)
			return (i);
		i++;
	}
	return (0);
}

void	find_cmd(t_cmd *cmd)
{
	int	i;

	i = find_path(cmd);
	cmd->path = ft_split(cmd->envp[i] + 5, ':');
	ft_access(cmd);
}


int	main(int argc, char **argv, char *envp[])
{
	t_cmd	cmd;
	int	i;
	pipe(cmd.pipefd);
	ft_init_struct(argc, argv, envp, &cmd);
	ft_malloc_pid(&cmd);
	i = 0;
	if (argc > 1)
			ft_fork(i, &cmd);
	free (cmd.pid);
	return (0);
}