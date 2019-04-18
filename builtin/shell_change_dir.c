/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_change_dir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:17:05 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/18 18:11:45 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_set_pwd(t_shell *sh)
{
	char	pwd[LINE_MAX];

	getcwd(pwd, LINE_MAX);
	shell_setenv(sh, "OLDPWD", shell_getvalue(sh, "PWD"));
	shell_setenv(sh, "PWD", pwd);
}

int		shell_change_dir(t_shell *sh)
{
	struct stat st;
	char		*directory;

	
	if (sh->argv[1] && ft_strequ(sh->argv[1], "-"))
	{
		if (!(directory = shell_getvalue(sh, "OLDPWD")))
			return (shell_print_error(SH_VAR_NOT_SET));
	}
	else if (sh->argv[1])
		directory = sh->argv[1];
	else if (!sh->argv[1])
	{
		if (!(directory = shell_getvalue(sh, "HOME")))
			return (shell_print_error(SH_VAR_NOT_SET));
	}
	if (access(directory, F_OK))
		return (ft_perror(directory, "no such file or directory"));
	else if (chdir(directory) != -1)
		shell_set_pwd(sh);
	else if (lstat(directory, &st) == -1)
		return (ft_perror(directory, "permission denied"));
	else if (!S_ISDIR(st.st_mode))
		return (ft_perror(directory, "not a directory"));
	return (0);	
}
