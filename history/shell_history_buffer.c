/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_history_buffer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 16:30:41 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/20 19:57:59 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_reset_history_ptr(t_shell *sh)
{
	sh->hist_ptr = NULL;
	shell_switch_flag(SCROLL);
	if (HISTORYFILE_OPENED)
	{
		close(sh->fd);
		shell_switch_flag(HFO);
	}
	if (RHF)
	{
		shell_free_buffer(sh->tmp);
		sh->tmp = NULL;
		shell_switch_flag(RHF);
	}
}

void	shell_save_input(t_shell *sh, char *input)
{
	t_buffer	*new;

	if (!input)
		return ;
	if (!(new = (t_buffer *)ft_memalloc(sizeof(t_buffer))))
		exit(shell_print_error(SH_MALLOC_ERROR));
	new->data = input;
	if (!sh->history)
	{
		new->id = 1;
		sh->history = new;
	}
	else if (sh->history->id == ft_atoi(shell_getvalue(sh, "HISTORYSIZE")))
	{
		shell_save_history(sh);
		new->id = 1;
		sh->history = new;
	}
	else
	{
		new->id = sh->history->id + 1;
		new->next = sh->history;
		sh->history->prev = new;
		sh->history = new;
	}
}

void	shell_save_to_tmp_buffer(t_shell *sh, char *line)
{
	t_buffer	*new;

	if (!line)
		return ;
	if (!(new = (t_buffer *)ft_memalloc(sizeof(t_buffer))))
		exit(shell_print_error(SH_MALLOC_ERROR));
	new->data = line;
	if (!sh->tmp)
		sh->tmp = new;
	else
	{
		new->next = sh->tmp;
		sh->tmp->prev = new;
		sh->tmp = new;
	}
}
