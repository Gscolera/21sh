#include "shell.h"

void	shell_manage_input(t_shell *sh)
{
	if (sh->rd.input)
	{
		shell_get_commands(sh);
	}
}
