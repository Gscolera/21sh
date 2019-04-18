#include "shell.h"

int		shell_print_error(int errno)
{
	if (errno == SH_MALLOC_ERROR)
		ft_perror("shell", "memory allocation failed");
	else if (errno == SH_TERM_NOT_DEF)
		ft_perror("shell", "terminal type is not defined");
	else if (errno == SH_TERM_NO_ACCESS)
		ft_perror("shell", "no access to termcap database");
	else if (errno == SH_VAR_NOT_SET)
		ft_perror("shell", "variable is not set");
	return (errno);
}
