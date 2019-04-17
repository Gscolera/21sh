/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_get_cursor_position.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 19:10:52 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/13 19:11:30 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_get_cursor_position(struct s_coord *cursor)
{
	char buf[15];
	int ret;
	int i;
	
	i = -1;	
	write(fileno(stdout), "\033[6n", 4);
	ret = read(0, buf, 15);
	ft_memset(cursor, 0, sizeof(struct s_coord));
	while (++i < ret && buf[i] != ';')
	{
		if (ft_isdigit(buf[i]))
			cursor->y = cursor->y * 10 + buf[i] - 48;
	}
	while (i < ret)
	{
		if (ft_isdigit(buf[i]))
			cursor->x = cursor->x * 10 + buf[i] - 48;
		i++;
	}
}
