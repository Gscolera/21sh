#include "shell.h"

void	shell_next_cur_pos(t_reader *rd)
{
	cursor_right(rd);
	if (READING)
		rd->cp += 1;
	if (NEW_STRING)
	{
		shell_set_bg_to_line();
		cursor_goto(rd, 1, rd->crs.y);
	}
}

void	shell_prev_cur_pos(t_reader *rd)
{
	cursor_left(rd);
	if (READING)
		rd->cp -= 1;
}

void	shell_cursor_home(t_reader *rd, char direction)
{
	if (direction == 'H' && READING)
	{
		cursor_goto(rd, rd->home.x, rd->home.y);
		rd->cp = 0;
	}
	else if (READING)
	{
		while (rd->cp != rd->il)
			shell_next_cur_pos(rd);
	}
}

