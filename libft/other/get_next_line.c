/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:01:03 by gscolera          #+#    #+#             */
/*   Updated: 2018/12/01 18:32:24 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_line(const int fd, char *buffer, size_t buff_size)
{
	char	c;
	int		ret;
	size_t	i;

	if (fd < 0 || !buffer || !buff_size || read(fd, &c, 1) == -1)
		return (-1);
	ret = 1;
	c = 0;
	i = 0;
	ft_bzero(buffer, buff_size--);
	while (ret && c != '\n' && i < buff_size)
	{
		if (c)
			buffer[i++] = c;
		ret = read(fd, &c, 1);
	}
	return (ret);
}
