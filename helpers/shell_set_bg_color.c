#include "shell.h"

void	shell_set_bg_to_line(void)
{
	size_t	x;

	x = g_winsize.x;
	while (x--)
	{
		ft_putchar(' ');
	}
}

void	shell_set_bg_color(t_shell *sh, t_reader *rd)
{
	size_t	y;

	y = g_winsize.y;
	TPUTS(SCREEN_CLEAR);
	ft_putstr(BG_DEFAULT_COLOR);
	while (y--)
	{
		shell_set_bg_to_line();
	}
	rd->crs.x = g_winsize.x;
	rd->crs.y = g_winsize.y;
	cursor_goto(rd, 1, 1);
}


