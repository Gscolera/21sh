#include "shell.h"

void	shell_mvcr(t_shell *sh, t_reader *rd)
{
	if (sh->crs[CURRENT].x < g_winsize.x)
	{
		ACTION(CRS_RIGHT);
		sh->crs[CURRENT].x++;
	}
	else
	{
		shell_mvcd(sh, rd);
	}
	(READING) ? ++rd->cp : 0;
}

void	shell_mvcl(t_shell *sh, t_reader *rd)
{
	if (sh->crs[CURRENT].x > 1)
	{
		ACTION(CRS_LEFT);
		sh->crs[CURRENT].x--;
	}
	else
	{
		shell_goto(sh, g_winsize.x, sh->crs[CURRENT].y - 1);
	}
	(READING) ? --rd->cp : 0;
}

void	shell_mvcd(t_shell *sh, t_reader *rd)
{
	if (sh->crs[CURRENT].y < g_winsize.y)
	{
		ACTION(CRS_DOWN);
		sh->crs[CURRENT].y++;
		sh->crs[CURRENT].x = 1;
	}
	else
	{
		ACTION(CRS_DOWN);
		shell_set_bg_to_line(sh);
		shell_goto(sh, 1, g_winsize.y);
		sh->crs[CURRENT].x = 1;
		sh->crs[HOME].y--;
	}
}

void	shell_mvcu(t_shell *sh, t_reader *rd)
{
	if (sh->crs[CURRENT].y > 1)
	{
		ACTION(CRS_UP);
		sh->crs[CURRENT].y--;
	}
}

void	shell_goto(t_shell *sh, size_t x, size_t y)
{
	if (y <= g_winsize.y && y > 0 && x <= g_winsize.x && x > 0)
	{
		while (sh->crs[CURRENT].y != y)
		{
			(sh->crs[CURRENT].y < y) ? ACTION(CRS_DOWN) : ACTION(CRS_UP);
			(sh->crs[CURRENT].y < y) ? sh->crs[CURRENT].x = 1 : 0;
			sh->crs[CURRENT].y += (sh->crs[CURRENT].y < y) ? 1 : -1;
		}
		while (sh->crs[CURRENT].x != x)
		{
			(sh->crs[CURRENT].x < x) ? ACTION(CRS_RIGHT) : ACTION(CRS_LEFT);
			sh->crs[CURRENT].x += (sh->crs[CURRENT].x < x) ? 1 : -1;
		}
	}
}
