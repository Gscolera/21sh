#include "shell.h"

void	shell_mvcr(t_shell *sh, t_reader *rd)
{
	if (rd->crs.x < g_winsize.x)
	{
		ACTION(CRS_RIGHT);
		rd->crs.x++;
	}
	else
	{
		shell_mvcd(sh, rd);
	}
	(READING) ? ++rd->cp : 0;
}

void	shell_mvcl(t_shell *sh, t_reader *rd)
{
	if (rd->crs.x > 1)
	{
		ACTION(CRS_LEFT);
		rd->crs.x--;
	}
	else
	{
		shell_mvcu(rd);
		while (rd->crs.x < g_winsize.x)
		{
			ACTION(CRS_RIGHT);
			rd->crs.x++;
		}
	}
	(READING) ? --rd->cp : 0;
}

void	shell_mvcd(t_shell *sh, t_reader *rd)
{
	ACTION(CRS_DOWN);
	if (rd->crs.y < g_winsize.y)
	{
		rd->crs.y++;
		rd->crs.x = 1;
	}
	else
	{
		shell_set_bg_to_line();
		shell_goto(sh, rd, 1, g_winsize.y);
		rd->crs.x = 1;
		rd->home.y--;
	}
}

void	shell_mvcu(t_reader *rd)
{
	if (rd->crs.y > 1)
	{
		ACTION(CRS_UP);
		rd->crs.y--;
	}
}

void	shell_goto(t_shell *sh, t_reader *rd, size_t x, size_t y)
{
	if (y <= g_winsize.y && y > 0 && x <= g_winsize.x && x > 0)
	{
		while (rd->crs.y != y)
		{
			if (rd->crs.y < y)
			{
				ACTION(CRS_DOWN);
				rd->crs.y++;
				rd->crs.x = 1;
			}
			else
			{
				ACTION(CRS_UP);
				rd->crs.y--;
			}
		}
		while (rd->crs.x != x)
		{
			(rd->crs.x < x) ? ACTION(CRS_RIGHT) : ACTION(CRS_LEFT);
			rd->crs.x += (rd->crs.x < x) ? 1 : -1;
				
		}
	}
}
