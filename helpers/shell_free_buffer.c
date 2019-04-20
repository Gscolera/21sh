/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_free_buffer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 19:55:40 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/20 19:58:27 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_free_buffer(t_buffer *buffer)
{
	t_buffer *tmp;

	while (buffer)
	{
		tmp = buffer->next;
		ft_strdel(&buffer->data);
		free(buffer);
		buffer = tmp;
	}
}
