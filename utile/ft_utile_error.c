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