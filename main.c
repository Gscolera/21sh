#include "shell.h"

int		main(void)
{
	struct s_shell	sh;

	shell_open(&sh);
	while (SHELLISON)
	{
		shell_read_input(&sh, &sh.rd);
		shell_manage_input(&sh);
		shell_execute_commands(&sh);
	}
	shell_close(&sh);
	exit(EXIT_SUCCESS);
}
