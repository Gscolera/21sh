/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_get_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:20:39 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/18 17:12:13 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	shell_get_internal_variables(t_shell *sh)
{
	char	buffer[20];

	ft_memset(buffer, 0, 20);
	shell_setenv(sh, "INTBS", ft_itoabuff(buffer, INTV_BUFFER_SIZE));
	ft_strclr(buffer);
	shell_setenv(sh, "?", "0");

}

void		shell_get_env(t_shell *sh)
{
	extern char **environ;

	sh->env = ft_copy_array(environ);
	if ((sh->intv = ft_allocate_array(INTV_BUFFER_SIZE)))
		shell_get_internal_variables(sh);
}
