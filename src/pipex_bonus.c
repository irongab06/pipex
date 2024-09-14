#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_cmd	cmd;
	int		i;

	i = 0;
	if (argc >= 5)
	{
		check_here_doc(&cmd, argv);
		ft_init_struct(&cmd, argc);
		find_path(&cmd, envp);
		i = ft_init_and_error(&cmd, i);
		if (i == 0)
			return (ft_fork(&cmd, argv, envp));
		ft_free(&cmd);
	}
	return (1);
}
