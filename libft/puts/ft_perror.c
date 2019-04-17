/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:46:06 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/12 14:46:14 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_perror(char *cmd, char *error)
{
	ft_putstr_fd(cmd, fileno(stderr));
	ft_putstr_fd(": ", fileno(stderr));
	ft_putstr_fd("\33[31m", fileno(stderr));
	ft_putstr_fd(error, fileno(stderr));
	ft_putstr_fd("\n\33[0m", fileno(stderr));
	return (1);
}
