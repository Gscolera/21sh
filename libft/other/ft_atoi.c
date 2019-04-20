/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:14:21 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/20 16:35:39 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long long	nb;
	int			n;
	int			i;

	nb = 0;
	n = 1;
	i = 0;
	if (!str)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45)
		n *= -1;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (ft_isdigit(str[i]) == 1)
		nb = nb * 10 + str[i++] - 48;
	return (nb * n);
}
