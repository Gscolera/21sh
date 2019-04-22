/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_run_binary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:26:32 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/18 14:19:40 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char	*shell_find_binary(t_shell *sh)
{
	char	*binary;
	char	**path;
	int		i;

	binary = NULL;
	if (access(sh->argv[0], F_OK))
	{
		path = ft_strsplit(shell_get_value(sh, "PATH"), ':');
		if (path)
		{
			i = -1;
			while (path[++i] && !binary)
			{
				binary = ft_pathcat(path[i], sh->argv[0]);
				if (access(binary, F_OK))
					ft_strdel(&binary);
			}
			ft_free_array(path);
		}
	}
	else
		binary = ft_strdup(sh->argv[0]);
	return (binary);
}

static void	shell_print_signal(int signal)
{
	if (signal == SIGSEGV)
		ft_perror("shell", "segmentation fault");
	if (signal == SIGBUS)
		ft_perror("shell", "bus error");
}

void			shell_run_binary(t_shell *sh)
{
	char	*binary;
	pid_t	pid;
	int		state;

	binary = shell_find_binary(sh);
	if (binary)
	{
		pid = fork();
		if (pid == -1)
			exit(shell_print_error(SH_FORK_ERROR));
		if (!pid)
		{
			execve(binary, sh->argv, sh->env);
			exit(EXIT_SUCCESS);
		}
		else
			waitpid(pid, &state, 0);
		(WIFSIGNALED(state)) ? shell_print_signal(WTERMSIG(state)) : 0;
	}
}
