/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_get_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 21:05:20 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/23 21:21:03 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	shell_add_command(t_shell *sh, t_command *cmd)
{
	t_command *tmp;

	if (!sh->cmd)
	{
		sh->cmd = cmd;
	}
	else
	{
		tmp = sh->cmd;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = cmd;
	}
}

static char	*shell_get_next_command(t_shell *sh, char *input)
{
	int			i;

	if (!(sh->cmd_ptr = (t_command *)ft_memalloc(sizeof(t_command))))
		exit(shell_print_error(SH_MALLOC_ERROR));
	i = -1;
	while (++i < CMD_MAX - 1)
	{
	
	}
	return (input);
}

static char	*shell_get_command_options(t_shell *sh, char *input)
{
	if (!*input)
		return (input);
	else if (ft_strnequ(input, "||", 2))
	{
		sh->cmd_ptr->options |= OR;
		return (input + 2);
	}
	else if (ft_strnequ(input, "&&", 2))
	{
		sh->cmd_ptr->options |= AND;
		return (input + 2);
	}
	else if (*input == '|')
		sh->cmd_ptr->options |= PIPE;
	return (input + 1);
}

void		shell_get_commands(t_shell *sh, char *input)
{
	while (*input)
	{
		input = shell_get_next_command(sh, input);
		shell_expand_string(sh, sh->cmd_ptr->line, CMD_MAX);
		if (CMD_LEN_OVERFLOW)
			shell_print_error(CLO);
		input = shell_get_command_options(sh, input);
		input++;
	}	
}
