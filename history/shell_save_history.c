/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_save_history.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 17:29:31 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/23 21:21:41 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		shell_create_history(t_shell *sh, int fd)
{
	while (sh->history)
	{
		sh->hist_ptr = sh->history->next;
		ft_putendl_fd(sh->history->data, fd);
		ft_strdel(&sh->history->data);
		free(sh->history);
		sh->history = sh->hist_ptr;
	}
	sh->hist_last = NULL;
}

static int		shell_edit_history(t_shell *sh, int fd)
{
	int		backup_file;
	char	buffer[CMD_MAX];
	size_t	hist_file_size;
	size_t	history_size;

	backup_file = open(".tmp", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (backup_file == -1)
		return (ft_perror("shell", "unable to create backup file"));
	hist_file_size = shell_get_num_value(sh, "HISTFILESIZE");
	history_size = (sh->history) ? sh->history->id : 0;
	shell_create_history(sh, backup_file);
	while (++history_size <= hist_file_size)
	{
		if (get_next_line(fd, buffer, CMD_MAX))
		{
			ft_putendl_fd(buffer, backup_file);
		}
		else
		{
			break ;
		}
	}
	close(sh->fd);
	close(backup_file);
	return (0);
}

int			shell_save_history(t_shell *sh)
{
	char	*hsfile;

	if (!(hsfile = shell_get_value(sh, "HSFILE")))
		hsfile = HSFILE;
	if (!access(hsfile, F_OK))
	{
		if ((sh->fd = open(hsfile, O_RDWR)) == -1)
			return (ft_perror(hsfile, "unable to open history file"));
		if (shell_edit_history(sh, sh->fd))
			return (-1);
		remove(hsfile);
		rename(".tmp", hsfile);
	}
	else
	{
		if ((sh->fd = open(hsfile, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR)) == -1)
			return (ft_perror(hsfile, "unable to create history file"));
		shell_create_history(sh, sh->fd);
		close(sh->fd);
	}
	return (0);
}
