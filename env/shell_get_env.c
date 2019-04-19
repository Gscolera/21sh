/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_get_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:20:39 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/19 16:15:22 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	shell_read_shellrc(t_shell *sh)
{
	int 	fd;
	int		i;
	char	*line;

	if (!access(SHELLRC, F_OK) && !access(SHELLRC, R_OK))
	{
		i = -1;
		fd = open(SHELLRC, O_RDONLY);
		while (get_next_line(fd, &line))
		{
			if (line[0] == '#')
				ft_strdel(&line);
			else if (++i < INTV_BUFFER_SIZE)
				sh->intv[i] = line;
		}
		close(fd);
	}
}

static void	shell_get_internal_variables(t_shell *sh)
{
	shell_read_shellrc(sh);
	shell_setenv(sh, "INTBS", "50");
	if (!shell_getvalue(sh, "HISTSIZE")) 
		shell_setenv(sh, "HISTSIZE", "50");
	if (!shell_getvalue(sh, "HISTFILESIZE"))
		shell_setenv(sh, "HISTFILESIZE", "1000");
	if (!shell_getvalue(sh, "HSFILE"))
		shell_setenv(sh, "HSFILE", ".history");
	if (!shell_getvalue(sh, "PS1"))
		shell_setenv(sh, "PS1", "\033[1;32m$USER\033[33m$PWD");
	shell_setenv(sh, "?", "0");

}

void		shell_get_env(t_shell *sh)
{
	extern char **environ;

	sh->env = ft_copy_array(environ);
	if ((sh->intv = ft_allocate_array(INTV_BUFFER_SIZE)))
		shell_get_internal_variables(sh);
}
