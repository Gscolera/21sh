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

static void	shell_history_push_back(t_shell *sh, char *data)
{
	t_buffer	*new_list;
	t_buffer	*tmp;

	if (!data)
		exit(shell_print_error(SH_MALLOC_ERROR));
	if (!(new_list = (t_buffer *)ft_memalloc(sizeof(t_buffer))))
		exit(shell_print_error(SH_MALLOC_ERROR));
	new_list->data = data;
	if (!sh->history)
		sh->history = new_list;
	else
	{
		tmp = sh->history;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_list;
		new_list->prev = tmp;
	}
}

int			shell_upload_prev_command(t_shell *sh, t_reader *rd)
{
	char	*hsfile;
	char	buffer[CMD_MAX];
	bool	gnl_return_value;

	if (!HISTORYFILE_OPENED)
	{
		if (!(hsfile = shell_get_value(sh, "HSFILE")))
			hsfile = HSFILE;
		if ((sh->fd = open(hsfile, O_RDONLY)) == -1)
			return (-1);
		TURN_ON(HFO);
	}
	gnl_return_value = get_next_line(sh->fd, buffer, CMD_MAX);
	if (gnl_return_value == 1)
		shell_history_push_back(sh, ft_strdup(buffer));
	return (gnl_return_value);
}

void		shell_prev_command(t_shell *sh, t_reader *rd)
{
	if (!sh->history || (sh->hist_ptr && !sh->hist_ptr->next))
	{
		if (shell_upload_prev_command(sh, rd) < 1)
			return ;
	}
	if (!SCROLLING)
	{
		sh->hist_ptr = sh->history;
		TURN_ON(SCROLL);
	}
	else
	{
		sh->hist_ptr = sh->hist_ptr->next;
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
		{
			shell_insert_string(rd, sh->hist_ptr->data);
		}
		else
		{
			shell_reset_history_ptr(sh);
		}
	}	
}
