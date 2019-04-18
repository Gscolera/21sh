#include "shell.h"

static bool	shell_builtin(char *command)
{
	return (ft_strequ(command, "cd") ||
			ft_strequ(command, "echo") ||
			ft_strequ(command, "unset") ||
			ft_strequ(command, "export") ||
			ft_strequ(command, "exit") ||
			ft_strequ(command, "env"));
}

static void	shell_execute_builtin(t_shell *sh)
{
	if (ft_strequ(sh->argv[0], "env"))
		shell_print_env(sh);
	else if (ft_strequ(sh->argv[0], "cd"))
		shell_change_dir(sh);
	else if (ft_strequ(sh->argv[0], "unset"))
		shell_unset_env(sh);
	else if (ft_strequ(sh->argv[0], "exit"))
		g_flags = 0;
}

void		shell_execute_command(t_shell *sh)
{
	if (sh->argv)
	{
		if (shell_builtin(sh->argv[0]))
			shell_execute_builtin(sh);
	}
	ft_strdel(&sh->input);
}
