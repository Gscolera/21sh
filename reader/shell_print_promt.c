#include "shell.h"

void	shell_print_promt(t_shell *sh, t_reader *rd)
{
	char *ps1;

	ps1 = shell_getvalue(sh, "PS1");
	if (!ps1)
	{
		ft_putstr(PS1_DEFAULT_COLOR);
		ft_putstr(shell_getvalue(sh, "USER"));
		ft_putstr("->");
		ft_putstr(PWD_DEFAULT_COLOR);
		ft_putstr(shell_getvalue(sh, "PWD"));
		ft_putstr(TEXT_DEFAULT_COLOR);
		ft_putstr("$ ");
	}
	else
		ft_printf("%s ", ps1);
}
