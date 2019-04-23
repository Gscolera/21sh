#include "shell.h"

static bool	shell_check_quotes(char *input)
{
	while (*input)
	{
		if (INPUT_IS_EMPTY && *input > 32)
			shell_deactivate_option(IE);
		if (SINGLE_QUOTE(*input) || DOUBLE_QUOTE(*input))
			shell_manage_quotes(*input);
		input++;
	}
	return ((IN_QUOTES) ? 0 : 1);
}

bool	shell_check_input(char *input)
{
	if (!shell_check_quotes(input) || INPUT_IS_EMPTY)
		return (0);
	return (1);
}
