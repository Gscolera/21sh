/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_clear_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 18:42:16 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/23 21:48:35 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_clear_input(t_reader *rd)
{
	ft_strclr(rd->input);
	rd->il = 0;
	rd->cp = 0;
	cursor_goto(rd, rd->home.x, rd->home.y);
	TPUTS(CRS_CLEAR);
}
