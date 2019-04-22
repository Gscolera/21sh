#include "shell.h"

static bool	shell_check_quotes(char *input)
{
	while (*input)
	{
		if (INPUT_EMPTY && *input > 32)
			shell_switch_flag(IE);
		if (SINGLE_QUOTE(*input) || DOUBLE_QUOTE(*input))
			shell_manage_quotes(*input);
		input++;
	}
	return ((IN_SINGLE_QUOTE || IN_DOUBLE_QUOTE) ? 0 : 1);
}

bool	shell_check_input(char *input)
{
	shell_switch_flag(IE);
	if (!shell_check_quotes(input) || INPUT_EMPTY)
		return (0);
	return (1);
}
