/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 21:33:46 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/18 16:20:33 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int num)
{
	int c;

	c = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num = num / 10;
		c++;
	}
	return (c);
}

char		*ft_itoa(int n)
{
	char		*tmp;
	size_t		len;
	size_t		sign;

	sign = (n < 0) ? 1 : 0;
	len = num_len(n);
	if (!(tmp = ft_strnew(len + sign)))
		return (NULL);
	if (sign)
		tmp[0] = '-';
	else if (n > 0)
		len--;
	else
		tmp[0] = '0';
	while (n)
	{
		if (n > 0)
			tmp[len] = '0' + (n % 10);
		else
			tmp[len] = '0' + -(n % 10);
		n = n / 10;
		len--;
	}
	return (tmp);
}

char		*ft_itoabuff(char *buff, int n)
{
	size_t		len;

	len = num_len(n);
	if (n < 0)
		buff[0] = '-';
	else if (n > 0)
		len--;
	else
		buff[0] = '0';
	while (n)
	{
		if (n > 0)
			buff[len] = '0' + (n % 10);
		else
			buff[len] = '0' + -(n % 10);
		n = n / 10;
		len--;
	}
	return (buff);
}
