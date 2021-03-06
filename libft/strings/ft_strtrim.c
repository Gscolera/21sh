/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:07:23 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/13 18:38:19 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char const	*tmp;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	if (*s == '\0')
		return (NULL);
	tmp = s + ft_strlen(s) - 1;
	while (*tmp == ' ' || *tmp == '\t' || *tmp == '\n')
		tmp--;
	return (ft_strsub(s, 0, tmp - s + 1));
}
