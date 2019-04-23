#include "shell.h"

void	shell_activate_option(int option)
{
	g_options |= option;
}

void	shell_deactivate_option(int option)
{
	g_options &= ~option;
}

void	shell_switch_option(int option)
{
	if (g_options & option)
	{
		shell_deactivate_option(option);
	}
	else
	{
		shell_activate_option(option);
	}
}
