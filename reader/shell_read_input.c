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

static void	shell_reset_reader(t_shell *sh, t_reader *rd)
{
	rd->il = 0;
	rd->cp = 0;
	rd->buffer_size = RD_BUFFER_SIZE;
	rd->input = (char *)ft_memalloc(RD_BUFFER_SIZE);
	if (!rd->input)
		exit(shell_print_error(SH_MALLOC_ERROR));
	shell_print_promt(sh, rd);
	tcsetattr(fileno(stdout), TCSANOW, &sh->shell_settings);	
	shell_get_cursor_position(&rd->home);
	rd->crs = rd->home;
	shell_switch_flag(READ);
}

static void	manage_escape(t_shell *sh, t_reader *rd, char *esc)
{
	if (ft_strequ(esc, rd->escape[KEY_LEFT]) && rd->cp > 0)
		shell_prev_cur_pos(rd);
	else if (ft_strequ(esc, rd->escape[KEY_RIGHT]) && rd->cp < rd->il)
		shell_next_cur_pos(rd);
	else if (ft_strequ(esc, rd->escape[KEY_UP]))
		NULL;
	else if (ft_strequ(esc, rd->escape[KEY_DOWN]))
		NULL;
	else if (ft_strequ(esc, rd->escape[KEY_HOME]))
		shell_cursor_home(rd, *esc);
	else if (ft_strequ(esc, rd->escape[KEY_END]))
		shell_cursor_home(rd, *esc);
	else if (ft_strequ(esc, rd->escape[KEY_DELETE]))
		ft_putstr(tgetstr("ho", NULL));
	ft_strclr(rd->buffer);
}

static void	manage_key(t_shell *sh, t_reader *rd, char key)
{
	if (key == KEY_ESCAPE)
		shell_switch_flag(READ | SHELL_ON);
	else if (key == KEY_BACKSPACE && rd->cp > 0)
	{
		shell_prev_cur_pos(rd);
		shell_delete_char(rd);
	}
	else if (key == KEY_ENTER)
		shell_switch_flag(READ);
}

static void	parse_buffer(t_shell *sh, t_reader *rd, char *buffer)
{
	while (*buffer)
	{
		if (ft_isprint(*buffer) && rd->il < CMD_MAX)
			shell_insert_char(sh, rd, *buffer);
		else if (ESCAPE(buffer))
			manage_escape(sh, rd, buffer + 2);
		else if (*buffer > 0)
			manage_key(sh, rd, *buffer);
		buffer++;
	}	
}

void	shell_read_input(t_shell *sh, t_reader *rd)
{
	shell_reset_reader(sh, rd);	
	while (READING)
	{
		read(fileno(stdout), rd->buffer, RD_BUFFER_SIZE);
		parse_buffer(sh, rd, rd->buffer);
		ft_strclr(rd->buffer);
	}
	tcsetattr(fileno(stdout), TCSANOW, &sh->default_settings);
	TPUTS(CRS_DOWN);
}
