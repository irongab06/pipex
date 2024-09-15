/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 08:22:55 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/13 18:09:52 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_cmd	cmd;
	int		i;

	i = 0;
	ft_printf("bonus %i\n", BONUS);
	if (((!BONUS && argc != 5) || (BONUS && argc < 5)))
	{
		ft_printf("wrong number of arguments !!!!!\n");
		return (1);
	}
	check_here_doc(&cmd, argv);
	ft_init_struct(&cmd, argc);
	find_path(&cmd, envp);
	i = ft_init_and_error(&cmd, i);
	if (i == 0)
		return (ft_fork(&cmd, argv, envp));
	ft_free(&cmd);
	return (1);
}
