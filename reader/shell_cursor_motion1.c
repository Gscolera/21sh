#include "shell.h"

void	shell_mvche(t_shell *sh, t_reader *rd, char direction)
{
	if (direction == 'H')
	{
		shell_goto(sh, sh->crs[HOME].x, sh->crs[HOME].y);
		rd->cp = 0;
	}
	else
	{
		shell_goto(sh, sh->crs[END].x, sh->crs[END].y);
		rd->cp = rd->il;
	}
}
