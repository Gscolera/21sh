#include "shell.h"

void	shell_manage_input(t_shell *sh)
{
	if (shell_check_input(sh->rd.input))
	{
		shell_get_commands(sh, sh->rd.input);
		ft_printf("%s\n", sh->rd.input);
		shell_save_input(sh, sh->rd.input);
	}
}
