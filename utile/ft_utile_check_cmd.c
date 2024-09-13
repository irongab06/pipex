/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utile_check_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:36:47 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/13 17:45:28 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_check_cmd(t_cmd *cmd, char **argv, int i)
{
	int	j;

	j = 0;
	if (access(argv[i + 2], X_OK) == 0)
	{
		cmd->path_buf = argv[i + 2];
		return ;
	}
	while (cmd->cmd_path[j] != NULL)
	{
		ft_init_buf(cmd, argv, i, j);
		if (access(cmd->path_buf, X_OK) == 0)
			return ;
		else
		{
			free(cmd->path_buf);
			cmd->path_buf = NULL;
		}
		j++;
	}
	write(2, argv[i + 2], ft_strlen(argv[i + 2]));
	write(2, ": command not found\n", 21);
	//ft_free(cmd);
	exit (127);
}


void	ft_init_buf(t_cmd *cmd, char **argv, int i, int j)
{
	int	len;

	len = ft_strlen(cmd->cmd_path[j]) + ft_strlen(argv[i + 2]) + 2;
	ft_malloc(&cmd->path_buf, len); //&cmd->path_buf
	ft_cpy_and_cat(cmd->path_buf, cmd->cmd_path[j], argv[i + 2], len);
}

void	ft_cpy_and_cat(char *buf, char *path, char *argv, int len)
{
	int	i;

	i = 0;
	ft_strlcpy(buf, path, len);
	ft_strlcat(buf, "/", len);
	i = ft_len_argv(argv);
	len = len - i;
	ft_strlcat(buf, argv, len);
}

int	ft_len_argv(char *argv)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (argv[i] != '\0' && argv[i] != ' ' )
		i++;
	while (argv[j] != '\0')
		j++;
	return (j - i);
}