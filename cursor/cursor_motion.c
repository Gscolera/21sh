#include "shell.h"

void	cursor_right(t_reader *rd)
{
	if (rd->crs.x < g_winsize.x)
	{
		TPUTS(CRS_RIGHT);
		rd->crs.x += 1;
	}
	else
	{
		TPUTS(CRS_NS);
		rd->crs.x = 1;
		if (rd->crs.y < g_winsize.y)
		{
			rd->crs.y += 1;
		}
		else
		{
			rd->home.y -= 1;
		}
	}
}

void	cursor_left(t_reader *rd)
{
	size_t	x;

	if (rd->crs.x > 1)
	{
		TPUTS(CRS_LEFT);
		rd->crs.x -= 1;
	}
	else if (rd->crs.y > 1)
	{
		x = g_winsize.x;
		cursor_up(rd);
		while (x--)
			TPUTS(CRS_RIGHT);
		rd->crs.x = g_winsize.x;
	}
}

void	cursor_up(t_reader *rd)
{
	if (rd->crs.y > 1)
	{
		TPUTS(CRS_UP);
		rd->crs.y -= 1;
	}
}

void	cursor_down(t_reader *rd)
{
	if (rd->crs.y < g_winsize.y)
	{
		TPUTS(CRS_DOWN);
		rd->crs.y += 1;
	}
}

void	cursor_goto(t_reader *rd, size_t x, size_t y)
{
	while (rd->crs.y != y && y > 0 && y <= g_winsize.y)
	{
		(rd->crs.y < y) ? cursor_down(rd) : cursor_up(rd);
	}
	while (rd->crs.x != x && x > 0 && x <= g_winsize.x)
	{
		(rd->crs.x < x) ? cursor_right(rd) : cursor_left(rd);
	}
}
