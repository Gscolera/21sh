/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:50:15 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/18 16:54:29 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	**ft_allocate_array(size_t size)
{
	char			**array;

	array = (char **)ft_memalloc(sizeof(char *) * (++size));
	while (size--)
		array[size] = NULL;
	return ((array) ? array : NULL);
}

void	ft_free_array(char **array)
{
	int	i;

	if (array)
	{
		i = -1;
		while (array[++i])
			ft_strdel(&array[i]);
		free(array);
	}
}

void	ft_print_array(char **array)
{
	int i;

	if (array)
	{
		i = -1;
		while (array[++i])
			ft_putendl(array[i]);
	}
}

size_t	ft_count_array(char **array)
{
	size_t	length;

	length = 0;
	if (array)
	{
		while (array[length])
			length++;
	}
	return (length);
}

char	**ft_copy_array(char **array)
{
	char	**new;
	size_t	i;
	size_t	length;

	i = 0;
	new = NULL;
	if ((length = ft_count_array(array)))
	{
		if ((new = ft_allocate_array(length)))
		{
			while (i < length)
			{
				new[i] = ft_strdup(array[i]);
				i++;
			}
		}
	}
	return (new);
}
