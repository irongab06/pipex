#include "../pipex.h"

void	check_here_doc(t_cmd *cmd, char **argv)
{
	if (ft_strncmp("here_doc", argv[1], 9) != 0)
	{
		cmd->index_here_doc = 0;
		return ;
	}
	else
	{
		cmd->index_here_doc = 1;
		here_doc(cmd, argv);
	}
}

void	here_doc(t_cmd *cmd, char **argv)
{
	char	*line;
	int		line_len;

	line_len = 0;
	line = NULL;
	cmd->fd_infile = open("limiter.tmp", O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (cmd->fd_infile < 0)
	{
		perror("Error opening here_doc file");
		exit (EXIT_FAILURE);
	}
	while (1)
	{
		write(STDOUT_FILENO, "> ", 2);
		line = get_next_line(STDIN_FILENO);
		line_len = ft_strlen(line);
		if (ft_strncmp(line, argv[2], (line_len - 1)) == 0)
			break ;
		write(cmd->fd_infile, line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(cmd->fd_infile);
}
