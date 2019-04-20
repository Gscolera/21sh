/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_cursor_advanced_movement.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:46:57 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/20 15:46:36 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_next_word(t_reader *rd)
{
	while (rd->cp < rd->il && rd->input[rd->cp] > 32)
		shell_next_cur_pos(rd);
	while (rd->cp < rd->il && rd->input[rd->cp] <= 32)
		shell_next_cur_pos(rd);
}

void	shell_prev_word(t_reader *rd)
{
	while (rd->cp > 0 && rd->input[rd->cp - 1] <= 32)
		shell_prev_cur_pos(rd);
	while (rd->cp > 0 && rd->input[rd->cp - 1] > 32)
		shell_prev_cur_pos(rd);
}

void	shell_next_line(t_reader *rd)
{
	if (rd->home.x + rd->il > g_winsize.x && rd->crs.y < g_winsize.y)
	{
		cursor_down(rd);
		rd->cp += g_winsize.x;
		while (rd->cp > rd->il)
			shell_prev_cur_pos(rd);
	}
}

void	shell_prev_line(t_reader *rd)
{
	if (rd->crs.y > rd->home.y)
	{
		cursor_up(rd);
		rd->cp -= g_winsize.x;
		while (rd->cp > rd->il)
			shell_next_cur_pos(rd);
	}
}
