#include "shell.h"

void	shell_mvche(t_shell *sh, t_reader *rd, char direction)
{
	if (direction == 'H' && READING)
	{
		shell_goto(sh, rd, rd->home.x, rd->home.y);
		rd->cp = 0;
	}
	else if (READING)
	{
		while (rd->cp != rd->il)
			shell_mvcr(sh, rd);
	}
}
