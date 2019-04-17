/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:12:40 by gscolera          #+#    #+#             */
/*   Updated: 2018/11/25 16:41:48 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *str, int fd)
{
	size_t	len;

	if (!str || fd < 0)
		return ;
	len = ft_strlen(str);
	write(fd, str, len);
	ft_putchar_fd('\n', fd);
}
