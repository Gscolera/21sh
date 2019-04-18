/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_unset_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:13:57 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/18 19:05:51 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	shell_move_pointers(char **array, int i)
{
	while (array[++i])
		array[i - 1] = array[i];
	array[i - 1] = NULL;
}

static bool	shell_unset_variable(char **array, char *var)
{
	int		i;
	size_t	varlen;

	i = -1;
	varlen = ft_strlen(var);
	while (array[++i])
	{
		if (ft_strnequ(array[i], var, varlen))
		{
			ft_strdel(&array[i]);
			shell_move_pointers(array, i);
			return (1);
		}
	}
	return (0);
}
int		shell_unset_env(t_shell *sh)
{

	if (!var || !shell_getvalue(sh, sh->argv[1]))
		return (-1);
	if (!shell_unset_variable(sh->env, sh->argv[1]))
		shell_unset_variable(sh->intv, sh->argv[1]);
	return (0);
}
