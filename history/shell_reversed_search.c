#include "shell.h"

static void	isearch_create_new_request(t_request *rq, t_reader *rd)
{
	ft_memset(rq, 0, sizeof(t_request));
	ft_strcpy(rq->line, rd->input);
	rq->len = ft_strlen(rq->line);
	shell_activate_option(SEARCH | MATCH);
}

static void	search_parse_buffer(t_reader *rd, t_request *rq)
{
	int	i;

	i = -1;
	while (rd->buffer[++i])
	{
		if (ft_isprint(rd->buffer[i]) && rq->len < CMD_MAX)
		{
			ft_insert_char(rq->line, rd->buffer[i], rq->len++);
		}
		else if (rd->buffer[i] == KEY_BACKSPACE && rq->len > 0)
		{
			ft_delete_char(rq->line, --rq->len);
			shell_prev_cur_pos(rd);
		}
		else if (rd->buffer[i] == KEY_ESCAPE || rd->buffer[i] == KEY_ENTER)
		{
			shell_deactivate_option(SEARCH);
			if (rd->buffer[i] == KEY_ESCAPE)
				shell_clear_input(rd);
		}
	}
}

static void	search_for_match(t_shell *sh, t_request *rq)
{
	if (!sh->history)
		shell_upload_prev_command(sh, &sh->rd);
	sh->hist_ptr = sh->history;
	while (sh->hist_ptr && !MATCH_FOUND)
	{
		if (ft_strstr(sh->hist_ptr->data, rq->line))
		{
			shell_insert_string(&sh->rd, sh->hist_ptr->data);
			shell_activate_option(MATCH);
		}
		if (!sh->hist_ptr->next)
			shell_upload_prev_command(sh, &sh->rd);
		sh->hist_ptr = sh->hist_ptr->next;
	}
}

static void	print_search_results(t_reader *rd, t_request *rq)
{
	shell_new_string(rd);
	if (MATCH_FOUND)
	{
		ft_putstr(SEARCH_COLOR_TRUE);
		shell_print_string(rd, "reversed_search> ");
		ft_putstr(END_OF_COLOR);
	}
	else
	{
		ft_putstr(SEARCH_COLOR_FALSE);
		shell_print_string(rd, "reversed_search_failed> ");
		ft_putstr(END_OF_COLOR);
	}
	ft_putstr(TEXT_DEFAULT_COLOR);
	shell_print_string(rd, rq->line);
}

void	shell_reversed_search(t_shell *sh, t_reader *rd)
{
	t_request	rq;
	if (SCROLLING)
		shell_reset_history_ptr(sh);
	isearch_create_new_request(&rq, rd);
	while (SEARCHING)
	{
		shell_clear_input(rd);
		LINE_EMPTY(rq.line) ? shell_activate_option(MATCH) : search_for_match(sh, &rq);
		print_search_results(rd, &rq);
		read(fileno(stdout), rd->buffer, RD_BUFFER_SIZE);
		search_parse_buffer(rd, &rq);
		ft_strclr(rd->buffer);
		shell_deactivate_option(MATCH);
	}
	shell_cursor_home(rd, 'E');
	TPUTS(CRS_CLEAR);
	shell_reset_history_ptr(sh);
}
