/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_expand_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 17:18:39 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/23 21:21:06 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_expand_string(t_shell *sh, char *cmd, size_t max_len)
{
	size_t	i;
	
	i = 0;
	while (cmd[i])
	{
		if (BACKSLASH(cmd[i]))
			ft_delete_char(cmd, i);
		i++;
	}
}
