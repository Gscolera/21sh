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

static void	shell_execute_builtin(t_shell *sh, char *command)
{
	if (ft_strequ(command, "env"))
		shell_print_env(sh);
	else if (ft_strequ(command, "cd"))
		shell_change_dir(sh);
	else if (ft_strequ(command, "unset"))
		shell_unset_env(sh);
	else if (ft_strequ(command, "exit"))
		g_options = 0;
}

static void	shell_go_to_the_next_command(t_shell *sh)
{
	t_command	*tmp;

	tmp = sh->cmd->next;
	ft_free_array(sh->cmd->argv);
	free(sh->cmd);
	sh->cmd = tmp;
}

void		shell_execute_commands(t_shell *sh)
{
	while (sh->cmd)
	{
		ft_putendl(sh->cmd->line);
		shell_go_to_the_next_command(sh);
	}
}
