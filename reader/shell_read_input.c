#include "shell.h"

void	print_seq(char *seq)
{
	while (*seq)
	{
		ft_printf("%d ", *seq);
		seq++;
	}
	ft_printf("\n");
}

static void	manage_escape(t_shell *sh, t_reader *rd, char *esc)
{
	if (ft_strequ(esc, sh->escape[KEY_LEFT]) && rd->cp > 0)
		shell_mvcl(sh, rd);
	else if (ft_strequ(esc, sh->escape[KEY_RIGHT]) && rd->cp < rd->il)
		shell_mvcr(sh, rd);
	else if (ft_strequ(esc, sh->escape[KEY_UP]))
		shell_mvcu(sh, rd);
	else if (ft_strequ(esc, sh->escape[KEY_DOWN]))
		shell_mvcd(sh, rd);
	else if (ft_strequ(esc, sh->escape[KEY_HOME]))
		shell_mvche(sh, rd, *esc);
	else if (ft_strequ(esc, sh->escape[KEY_END]))
		shell_mvche(sh, rd, *esc);
	ft_strclr(rd->buffer);
}

static void	manage_key(t_shell *sh, t_reader *rd, char key)
{
	if (key == KEY_ESCAPE)
		shell_switch_flag(READ | SHELL_ON);
	else if (key == KEY_BACKSPACE)
		NULL;
	else if (key == KEY_ENTER)
		shell_switch_flag(READ);
}

static void	parse_buffer(t_shell *sh, t_reader *rd, char *buffer)
{
	while (*buffer)
	{
		if (ft_isprint(*buffer))
			shell_insert_char(sh, rd, *buffer);
		else if (ESCAPE(buffer))
			manage_escape(sh, rd, buffer + 2);
		else if (*buffer > 0)
			manage_key(sh, rd, *buffer);
		buffer++;
	}	
}

void	shell_read_input(t_shell *sh)
{
	t_reader rd;

	shell_print_promt(sh);
	ft_memset(&rd, 0, sizeof(t_reader));
	tcsetattr(fileno(stdout), TCSANOW, &sh->shell_settings);	
	shell_get_cursor_position(&sh->crs[HOME]);
	sh->crs[CURRENT] = sh->crs[HOME];
	shell_switch_flag(READ);
	while (READING)
	{
		read(fileno(stdout), rd.buffer, ARG_MAX);
		parse_buffer(sh, &rd, rd.buffer);
		ft_strclr(rd.buffer);
	}
	sh->input = ft_strtrim(rd.input);
	tcsetattr(fileno(stdout), TCSANOW, &sh->default_settings);
	ACTION(CRS_DOWN);
}
