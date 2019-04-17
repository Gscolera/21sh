/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 21:42:42 by gscolera          #+#    #+#             */
/*   Updated: 2018/11/25 16:40:05 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char *str)
{
	size_t	len;

	if (!(len = ft_strlen(str)))
		return ;
	write(fileno(stdout), str, len);
	ft_putchar('\n');
}
