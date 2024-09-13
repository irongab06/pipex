/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utile_free_malloc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 08:40:33 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/13 15:12:33 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_free_pipe(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->pipefd != NULL)
	{
		while (i <= cmd->pipelen)
		{
			free(cmd->pipefd[i]);
			cmd->pipefd[i] = NULL; //ajoue par rapport a l ancien code;
			i++;
		}
		free(cmd->pipefd);
		cmd->pipefd = NULL;
	}
}

void	ft_malloc(char **buf, int len)
{
	*buf = malloc(sizeof(char *) * (len));
	if (*buf == NULL)
	{
		perror("malloc error");
		return ;
	}
}