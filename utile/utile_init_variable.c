/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_init_variable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:08:40 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/09 09:08:45 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_init_struct(int	argc, char **argv, char **envp, t_cmd *cmd)
{
	cmd->cmd_argv = argv;
	cmd->envp = envp;
	cmd->argc = argc;
	cmd->path = NULL;
	cmd->temp_argv = NULL;
}