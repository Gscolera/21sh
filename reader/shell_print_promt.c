#include "shell.h"

void	shell_print_promt(t_shell *sh, t_reader *rd)
{
	char *ps1;

	ps1 = shell_get_value(sh, "PS1");
	if (!ps1)
	{
		ft_putstr(PS1_DEFAULT_COLOR);
		ft_putstr(shell_get_value(sh, "USER"));
		ft_putstr("->");
		ft_putstr(PWD_DEFAULT_COLOR);
		ft_putstr(shell_get_value(sh, "PWD"));
		ft_putstr(TEXT_DEFAULT_COLOR);
		ft_putstr("$ ");
	}
	else
		ft_printf("%s ", ps1);
}
