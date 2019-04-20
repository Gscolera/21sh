/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_history_buffer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 16:30:41 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/20 17:43:18 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

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
	else
	{
		new->id = sh->history->id + 1;
		new->next = sh->history;
		sh->history = new;
	}
}
