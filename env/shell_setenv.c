/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_setenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:13:39 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/18 17:16:51 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	shell_add_variable(t_shell *sh, char *new_variable)
{
	int	i;
	int	buffsize;

	i = -1;
	while (sh->intv[++i])
		NULL;
	sh->intv[i] = new_variable;
}

static void	shell_set_new_value(t_shell *sh, char *new_env, char *var)
{
	int		i;
	bool	state;
	size_t	len;

	i = -1;
	state = false;
	len = ft_strlen(var);
	while (sh->env[++i] && !state)
	{
		if (ft_strnequ(sh->env[i], var, len))
		{
			ft_strdel(&sh->env[i]);
			sh->env[i] = new_env;
			state = true;
		}
	}
}

void	shell_setenv(t_shell *sh, char *var, char *value)
{
	char	*new_env;

	if (var && value)
	{
		new_env = ft_strnew(ft_strlen(var) + ft_strlen(value) + 1);
		if (!new_env)
			exit(shell_print_error(SH_MALLOC_ERROR));
		ft_strcat(new_env, var);
		ft_strcat(new_env, "=");
		ft_strcat(new_env, value);
	}
	if (shell_getvalue(sh, var))
	{
		shell_set_new_value(sh, new_env, var);
	}
	else
	{
		shell_add_variable(sh, new_env);
	}
}
