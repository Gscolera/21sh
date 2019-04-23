#include "shell.h"

void	shell_manage_input(t_shell *sh)
{
	if (shell_check_input(sh->rd.input))
	{
		ft_printf("%d\n", g_options);
		shell_save_input(sh, sh->rd.input);	
	}
	else if (INPUT_IS_EMPTY)
	{
		ft_printf("%d\n", g_options);
		ft_strdel(&sh->rd.input);
		shell_deactivate_option(IE);
	}
}
