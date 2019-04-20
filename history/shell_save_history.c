/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_save_history.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 17:29:31 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/20 19:27:41 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"


static void		shell_create_history(t_shell *sh, int fd)
{
	t_buffer	*tmp;

	while (sh->history)
	{
		tmp = sh->history->next;
		ft_putendl_fd(sh->history->data, fd);
		ft_strdel(&sh->history->data);
		free(sh->history);
		sh->history = tmp;
	}
}

static int		shell_edit_history(t_shell *sh, int fd)
{
	int		tmp;
	char	*line;
	size_t	id;
	size_t	hist_size;

	tmp = open(".tmp", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (tmp == -1)
		return (ft_perror("shell", "unable to create backup file"));
	id = sh->history->id;
	hist_size = ft_atoi(shell_getvalue(sh, "HISTFILESIZE"));
	shell_create_history(sh, tmp);
	ft_printf("%d %d", id, hist_size);
	while (get_next_line(fd, &line))
	{
		if (id++ < hist_size)
			ft_putendl_fd(line, tmp);
		ft_strdel(&line);
	}
	close(fd);
	close(tmp);
	return (0);
}

int			shell_save_history(t_shell *sh)
{
	char	*hsfile;
	int		fd;

	if (!(hsfile = shell_getvalue(sh, "HSFILE")))
		hsfile = HSFILE;
	if (!access(hsfile, F_OK))
	{
		if ((fd = open(hsfile, O_RDWR)) == -1)
			return (ft_perror(hsfile, "unable to open history file"));
		shell_edit_history(sh, fd);
		remove(hsfile);
		rename(".tmp", hsfile);
	}
	else
	{
		if ((fd = open(hsfile, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR)) == -1)
			return (ft_perror(hsfile, "unable to create history file"));
		shell_create_history(sh, fd);
		close(fd);
	}
	return (0);
}
