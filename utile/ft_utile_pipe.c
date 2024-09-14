/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utile_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 08:35:02 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/13 09:04:13 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_init_pipefd(t_cmd *cmd)
{
	int	i;

	i = 0;
	cmd->pipefd = ft_calloc((cmd->pipelen + 1), sizeof(int *));
	if (cmd->pipefd == NULL)
	{
		perror("Error allocating memory for pipefd");
		return (EXIT_FAILURE);
	}
	while (i <= cmd->pipelen)
	{
		cmd->pipefd[i] = ft_calloc(2, sizeof(int));
		if (cmd->pipefd[i] == NULL)
		{
			perror("Error allocating memory for pipefd");
			ft_free_pipe(cmd);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (ft_active_pipe(cmd));
}

int	ft_active_pipe(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (i <= cmd->pipelen)
	{
		if (pipe(cmd->pipefd[i]) == -1)
		{
			perror("Error creating pipe");
			ft_free_pipe(cmd);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (0);
}
