/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_reduce_input_length.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 21:40:46 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/23 21:42:04 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_reduce_input_length(t_reader *rd)
{
	if (rd->il > 1)
	{
		rd->il -= 1;
		if (!rd->il)
			shell_activate_option(IE);
	}
}
