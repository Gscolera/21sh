#include "shell.h"

void	shell_close(t_shell *sh)
{
	ft_free_array(sh->env);
	ft_free_array(sh->intv);
	ft_free_array(sh->argv);
}
