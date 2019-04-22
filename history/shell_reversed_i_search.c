#include "shell.h"

static void	isearch_create_new_request(t_request *rq, t_reader *rd)
{
	ft_memset(rq, 0, sizeof(t_request));
	ft_strcpy(rq->line, rd->input);
	rq->len = ft_strlen(rq->line);
	TURN_ON(ISEARCH | MATCH);
}

static void	isearch_parse_buffer(t_reader *rd, t_request *rq)
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
		}
		else if (rd->buffer[i] == KEY_ESCAPE)
		{
			ft_strclr(rd->buffer);
			TURN_OFF(ISEARCH | MATCH);
		}
	}
}

static void	isearch_print_results(t_reader *rd, t_request *rq)
{
	char	*ipromt;

	if (MATCH_FOUND)
	{
		ipromt = "\033[1;38;2;172;0;252mrevesred_i_search> \033[0m";
		shell_print_string(rd, rq->match);
		shell_new_string(rd);
		shell_print_string(rd, ipromt);
		shell_print_string(rd, rq->line);
	}
	else
	{
		ipromt = "reveresed_i_search_failed> ";
		shell_new_string(rd);
		shell_print_string(rd, ipromt);
		shell_print_string(rd, rq->line);
	}
}

void	shell_reversed_i_search(t_shell *sh, t_reader *rd)
{
	t_request	rq;
	if (SCROLLING)
		shell_reset_history_ptr(sh);
	isearch_create_new_request(&rq, rd);
	while (SEARCHING)
	{
		shell_clear_input(rd);
		shell_look_for_match(sh, &rq);
		isearch_print_results(rd, &rq);
		read(fileno(stdout), rd->buffer, RD_BUFFER_SIZE);
		isearch_parse_buffer(rd, &rq);
	}
	shell_cursor_home(rd, 'E');
	TPUTS(CRS_CLEAR);
	shell_reset_history_ptr(sh);
}
