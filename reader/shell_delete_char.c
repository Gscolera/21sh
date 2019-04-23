/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_delete_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:58:27 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/23 21:48:19 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_delete_char(t_reader *rd)
{
	rd->il -= 1;
	ft_delete_char(rd->input, rd->cp);
	TPUTS(CRS_CLEAR);
	TPUTS(CRS_SAVE);
	ft_putstr(&rd->input[rd->cp]);
	TPUTS(CRS_RESTORE);
}
