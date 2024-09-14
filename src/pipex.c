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

void debug(char *debug)
{
	int t = open("res", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	write(t, debug, ft_strlen(debug));
	write(t, "\n", 1);
	close(t);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	cmd;
	int	i;

	i = 0;
	
	if (argc >= 5)
	{
		check_here_doc(&cmd, argv);
		ft_init_struct(&cmd, argc);
		find_path(&cmd, envp);
		i = ft_init_and_error(&cmd, i);
		if (i == 0)
			return (ft_fork(&cmd, argv, envp));
	}
	return (1);
}