#include "shell.h"

void	shell_close(t_shell *sh)
{
	free_strings(sh->env);
	free_strings(sh->intv);
}
