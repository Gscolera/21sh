#include "shell.h"

void	shell_set_bg_to_line(t_shell *sh)
{
	size_t	x;

	x = g_winsize.x;
	while (x--)
	{
		ft_putchar(' ');
	}
}

void	shell_set_bg_color(t_shell *sh)
{
	size_t	x;
	size_t	y;

	sh->crs[CURRENT].x = g_winsize.x;
	sh->crs[CURRENT].y = g_winsize.y;
	y = sh->crs[CURRENT].y;
	ACTION(SCREEN_CLEAR);
	ft_putstr(BG_DEFAULT_COLOR);
	while (y--)
	{
		shell_set_bg_to_line(sh);
	}
	shell_goto(sh, 1, 1);
}


