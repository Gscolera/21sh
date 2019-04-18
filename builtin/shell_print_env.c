/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_print_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:33:49 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/18 18:10:09 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		shell_print_env(t_shell *sh)
{
	if (!sh->argv[1])
		ft_print_array(sh->env);
	else if (ft_strequ(sh->argv[1], "-i"))
		ft_print_array(sh->intv);
	return (0);
}
