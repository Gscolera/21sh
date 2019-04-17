#include "shell.h"

void	shell_get_winsize(void)
{
	struct winsize	w;

	ioctl(fileno(stdout), TIOCGWINSZ, &w);
	g_winsize.x = w.ws_col;
	g_winsize.y = w.ws_row;
}
