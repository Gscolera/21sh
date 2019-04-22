#include "shell.h"

void	shell_reset_reader(t_shell *sh, t_reader *rd)
{
	rd->il = 0;
	rd->cp = 0;
	rd->buffer_size = RD_BUFFER_SIZE;
	rd->input = (char *)ft_memalloc(RD_BUFFER_SIZE);
	if (!rd->input)
		exit(shell_print_error(SH_MALLOC_ERROR));
	shell_print_promt(sh, rd);
}

void	shell_continue_reading(t_shell *sh, t_reader *rd)
{
	rd->cp = rd->il;
	ft_strclr(rd->promt);
	if (IN_SINGLE_QUOTE)
	{
		ft_strcpy(rd->promt, "quote> ");
	}
	else
	{
		ft_strcpy(rd->promt, "double quote> ");
	}
	ft_putstr(rd->promt);
	TURN_OFF(SQT | DQT);
}

void	shell_set_reader(t_shell *sh, t_reader *rd)
{

	if (IN_QUOTES)
	{
		shell_continue_reading(sh, rd);
	}
	else
	{
		shell_reset_reader(sh, rd);
		TURN_ON(HE);
	}
	tcsetattr(fileno(stdout), TCSANOW, &sh->shell_settings);	
	shell_get_cursor_position(&rd->home);
	rd->crs = rd->home;
	TURN_ON(READ);

}
