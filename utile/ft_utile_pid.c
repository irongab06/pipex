/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utile_pid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 08:52:35 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/13 09:03:20 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_init_pid(t_cmd *cmd)
{
	cmd->pid = malloc(sizeof(pid_t) * (cmd->pipelen + 1));
	if (cmd->pid == NULL)
	{
		perror("Error allocating memory for pid");
		return (1);
	}
	return (0);
}
