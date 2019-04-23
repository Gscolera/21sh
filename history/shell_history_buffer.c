/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_history_buffer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 16:30:41 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/23 21:22:15 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_delete_uploaded_history(t_shell *sh)
{
		if (sh->hist_last)
		{
			shell_free_buffer(sh->hist_last->next);
			sh->hist_last->next = NULL;
		}
		else
		{
			shell_free_buffer(sh->history);
			sh->history = NULL;
		}
		close(sh->fd);
		shell_deactivate_option(HFO);
}

void	shell_reset_history_ptr(t_shell *sh)
{
	sh->hist_ptr = NULL;
	shell_deactivate_option(SCROLL);
	if (HISTORYFILE_OPENED)
		shell_delete_uploaded_history(sh);
}

void	shell_save_input(t_shell *sh, char *input)
{
	t_buffer	*new;

	if (!(new = (t_buffer *)ft_memalloc(sizeof(t_buffer))))
		exit(shell_print_error(SH_MALLOC_ERROR));
	new->data = input;
	if (!sh->history)
	{
		new->id = 1;
		sh->history = new;
		sh->hist_last = new;
	}
	else
	{
		new->id = sh->history->id + 1;
		new->next = sh->history;
		sh->history->prev = new;
		sh->history = new;
		if (sh->history->id > shell_get_num_value(sh, "HISTSIZE"))
			shell_save_history(sh);
	}
}
