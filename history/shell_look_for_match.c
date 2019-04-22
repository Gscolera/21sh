#include "shell.h"

void	shell_look_for_match(t_shell *sh, t_request *rq)
{
	TURN_OFF(MATCH);
	if (!sh->history)
		shell_upload_prev_command(sh, &sh->rd);
	sh->hist_ptr = sh->history;
	while (sh->hist_ptr && !MATCH_FOUND)
	{
		if (ft_strrstr(sh->hist_ptr->data, rq->line))
		{
			rq->match = sh->hist_ptr->data;
			sh->hist_ptr->data = NULL;
			TURN_ON(MATCH);
		}
		if (!sh->hist_ptr->next)
			shell_upload_prev_command(sh, &sh->rd);
		sh->hist_ptr = sh->hist_ptr->next;
	}
}
