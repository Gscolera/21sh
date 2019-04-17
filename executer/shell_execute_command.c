#include "shell.h"

static char	*shell_find_binary(t_shell *sh)
{
	char	*binary;
	char	**path;
	int		i;

	binary = NULL;
	if (access(sh->argv[0], F_OK))
	{
		path = ft_strsplit(shell_getvalue(sh, "PATH"), ':');
		if (path)
		{
			i = -1;
			while (path[++i] && !binary)
			{
				binary = ft_pathcat(path[i], sh->argv[0]);
				ft_printf("%s\n", binary);
				if (access(binary, F_OK))
					ft_strdel(&binary);
			}
			free_strings(path);
		}
	}
	else
		binary = ft_strdup(sh->argv[0]);
	return (binary);
}

static void	shell_print_signal(int signal)
{
	if (signal == SIGSEGV)
		ft_perror("shell", "segmentation fault");
	if (signal == SIGBUS)
		ft_perror("shell", "bus error");
}

int			shell_execute_command(t_shell *sh)
{
	char	*binary;
	pid_t	pid;
	int		state;

	binary = shell_find_binary(sh);
	if (binary)
	{
		pid = fork();
		if (pid == -1)
			return (shell_print_error(sh, SH_FORK_ERROR));
		if (!pid)
		{
			execve(binary, sh->argv, sh->env);
			exit(EXIT_SUCCESS);
		}
		else
			waitpid(pid, &state, 0);
		(WIFSIGNALED(state)) ? shell_print_signal(WTERMSIG(state)) : 0;
	}
	ft_printf("HEllo");
}
