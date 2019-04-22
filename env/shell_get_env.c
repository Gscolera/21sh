/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_get_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:20:39 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/20 16:53:53 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	shell_read_shellrc(t_shell *sh)
{
	int		i;
	char	buffer[ENV_MAX];
	size_t	env_size;

	if (!(env_size = shell_get_num_value(sh, "INTBS")))
		env_size = INTV_BUFFER_SIZE;
	if (!access(SHELLRC, F_OK) && !access(SHELLRC, R_OK))
	{
		i = 0;
		sh->fd = open(SHELLRC, O_RDONLY);
		while (get_next_line(sh->fd, buffer, ENV_MAX))
		{
			if (!IS_COMMENT(buffer) && ++i < env_size)
				sh->intv[i] = ft_strdup(buffer);
		}
		close(sh->fd);
	}
}

static void	shell_get_internal_variables(t_shell *sh)
{
	char buffer[21];

	ft_memset(buffer, 0, 21);
	shell_read_shellrc(sh);
	shell_setenv(sh, "INTBS", ft_itoabuff(buffer, INTV_BUFFER_SIZE));
	if (!shell_get_value(sh, "HISTSIZE")) 
		shell_setenv(sh, "HISTSIZE", HISTSIZE);
	if (!shell_get_value(sh, "HISTFILESIZE"))
		shell_setenv(sh, "HISTFILESIZE", HISTFILESIZE);
	if (!shell_get_value(sh, "HSFILE"))
		shell_setenv(sh, "HSFILE", HSFILE);
	shell_setenv(sh, "?", "0");

}

void		shell_get_env(t_shell *sh)
{
	extern char **environ;

	sh->env = ft_copy_array(environ);
	if ((sh->intv = ft_allocate_array(INTV_BUFFER_SIZE)))
		shell_get_internal_variables(sh);
}
