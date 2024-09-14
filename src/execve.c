/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:58:55 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/13 17:40:42 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_execve(t_cmd *cmd, char **argv, char **envp, int i)
{

	cmd->cmd_execve = ft_split(argv[i + cmd->shift], ' '); //
	if (cmd->cmd_execve == NULL)
	{
		perror("ft_split failed");
		exit (EXIT_FAILURE);
	}
	if (execve(cmd->path_buf, cmd->cmd_execve, envp) == -1)
	{
		perror("execve failed");
		//free_execve;
		exit(EXIT_FAILURE);
	}
}