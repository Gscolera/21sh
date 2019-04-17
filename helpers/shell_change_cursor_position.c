#include "shell.h"

void	shell_next_cursor_position(struct s_coord *crs)
{
	crs->x = (crs->x < g_winsize.x) ? crs->x + 1 : 1;
	if (crs->x == 1 && crs->y < g_winsize.y)
	{
		crs->y++;
	}
}

void	shell_prev_cursor_position(struct s_coord *crs)
{

}
