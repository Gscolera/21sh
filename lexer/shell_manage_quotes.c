#include "shell.h"

void	shell_manage_quotes(char quote)
{
	if (SINGLE_QUOTE(quote) && !IN_DOUBLE_QUOTE)
	{
		shell_switch_option(SQT);
	}
	else if (DOUBLE_QUOTE(quote) && !IN_SINGLE_QUOTE)
	{
		shell_switch_option(DQT);
	}
}
