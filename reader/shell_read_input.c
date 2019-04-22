#include "shell.h"

static void	parse_buffer(t_shell *sh, t_reader *rd, char *buffer)
{
	while (*buffer)
	{
		if (ft_isprint(*buffer))
		{
			shell_insert_char(rd, *buffer);
			if (SCROLLING)
				shell_reset_history_ptr(sh);
		}
		else if (ESCAPE(buffer))
			shell_manage_escape(sh, rd, buffer + 2);
		else if (*buffer > 0)
			shell_manage_key(sh, rd, *buffer);
		buffer++;
	}	
}

void	shell_read_input(t_shell *sh, t_reader *rd)
{
	shell_set_reader(sh, rd);
	while (READING)
	{
		read(fileno(stdout), rd->buffer, RD_BUFFER_SIZE);
		parse_buffer(sh, rd, rd->buffer);
		ft_strclr(rd->buffer);
	}
	shell_cursor_home(rd, 'F');
	tcsetattr(fileno(stdout), TCSANOW, &sh->default_settings);
	TPUTS(CRS_NS);
}
