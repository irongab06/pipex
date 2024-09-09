/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_cpy_cat_malloc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:08:23 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/09 09:08:25 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../pipex.h"

void	ft_malloc(char **buf, int len)
{
	*buf = malloc(sizeof(char *) * (len));
	if (*buf == NULL)
	{
		perror("malloc error");
		exit (1);
	}
}

void	ft_malloc_pid(t_cmd *cmd)
{
	cmd->pid = malloc(sizeof(pid_t) * (cmd->argc - 1));
	if (cmd->pid == NULL)
	{
		perror("error malloc pid");
		exit (1);
	}
}

void	ft_cpy_and_cat(char *buf, char *path, char *argv, int len)
{
		ft_strlcpy(buf, path, len);
		ft_strlcat(buf, "/", len);
		ft_strlcat(buf, argv, len);
}