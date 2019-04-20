/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_unset_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:13:57 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/20 16:53:43 by gscolera         ###   ########.fr       */
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
		if (ft_strnequ(array[i], var, varlen) && array[i][varlen] == '=')
		{
			ft_strdel(&array[i]);
			shell_move_pointers(array, i);
			return (1);
		}
	}
	return (0);
}

static bool	shell_critical_variable(char *variable)
{
	return (ft_strequ(variable, "HISTSIZE") ||
			ft_strequ(variable, "HISTFILESIZE") || 
			ft_strequ(variable, "INTBS"));
}

int		shell_unset_env(t_shell *sh)
{
	int		i;

	if (!sh->argv[1])
		return (ft_perror("unset", "not enough arguments"));
	else if (shell_critical_variable(sh->argv[1]))
		return (ft_perror(sh->argv[1], "can't unset critical variable"));
	i = -1;
	while (sh->argv[++i])
	{
		shell_unset_variable(sh->env, sh->argv[1]);
	}
	return (0);
}
