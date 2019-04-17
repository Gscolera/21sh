#include "shell.h"

int		main(void)
{
	struct s_shell	sh;

	shell_open(&sh);
	while (SHELLISON)
	{
		shell_read_input(&sh);
		shell_manage_input(&sh);
		shell_execute_command(&sh);
	}
	shell_close(&sh);
	exit((sh.error) ? EXIT_FAILURE : EXIT_SUCCESS);
}
