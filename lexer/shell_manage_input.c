#include "shell.h"

void	shell_manage_input(t_shell *sh)
{
	if (sh->input)
	{
		sh->argv = ft_strsplit(sh->input, ' ');
	}
}
