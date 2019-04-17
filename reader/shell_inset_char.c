#include "shell.h"

void	shell_insert_char(t_shell *sh, t_reader *rd, char c)
{
	if (rd->il++ < ARG_MAX)
	{
		ft_insert_char(rd->input, c, rd->cp);
		ACTION(CRS_SAVE);
		ft_putstr(&rd->input[rd->cp]);
		shell_get_cursor_position(&sh->crs[END]);
		ACTION(CRS_RESTORE);
		shell_mvcr(sh, rd);
	}

}
