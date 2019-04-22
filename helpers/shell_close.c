/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 16:56:48 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/20 17:29:27 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "shell.h"

void		shell_close(t_shell *sh)
{
	if (HISTORYFILE_OPENED)
		shell_delete_uploaded_history(sh);
	shell_save_history(sh);
	ft_free_array(sh->env);
	ft_free_array(sh->intv);
	ft_free_array(sh->argv);
}
