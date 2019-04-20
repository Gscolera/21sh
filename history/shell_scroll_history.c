/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_scroll_history.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 18:26:45 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/20 19:57:54 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	shell_upload_prev_command(t_shell *sh, t_reader *rd)
{
	char	*hsfile;
	char	*line;

	if (!HISTORYFILE_OPENED)
	{
		if (!(hsfile = shell_getvalue(sh, "HSFILE")))
			hsfile = HSFILE;
		if ((sh->fd = open(hsfile, O_RDONLY)) == -1)
			return (ft_perror("shell", "unable to open history file"));
		shell_switch_flag(HFO);
	}
	get_next_line(sh->fd, &line);
	shell_save_to_tmp_buffer(sh, line);
	return (0);
}

void		shell_prev_command(t_shell *sh, t_reader *rd)
{
	if (SCROLLING && sh->hist_ptr)
	{
		sh->hist_ptr = sh->hist_ptr->next;
	}
	else if (!SCROLLING)
	{
		sh->hist_ptr = sh->history;
		shell_switch_flag(SCROLL);
	}
	if (!sh->hist_ptr && !READING_HSFILE)
	{
		shell_upload_prev_command(sh, rd);
		sh->hist_ptr = sh->tmp;
		shell_switch_flag(RHF);
	}
	if (sh->hist_ptr)
	{
		shell_clear_input(rd);
		shell_insert_string(rd, sh->hist_ptr->data);
	}
}

void		shell_next_command(t_shell *sh, t_reader *rd)
{
	if (sh->hist_ptr)
	{
		sh->hist_ptr = sh->hist_ptr->prev;
		shell_clear_input(rd);
		if (sh->hist_ptr)
			shell_insert_string(rd, sh->hist_ptr->data);
		else
			shell_switch_flag(SCROLL);
	}	
}
