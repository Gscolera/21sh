#include "shell.h"

void	shell_insert_char(t_reader *rd, char c)
{
	if (rd->il == rd->buffer_size - 2)
	{
		rd->input = (char *)ft_realloc(rd->input, rd->buffer_size, 
										rd->buffer_size + RD_BUFFER_SIZE);
		if (!rd->input)
			exit(shell_print_error(SH_MALLOC_ERROR));
		rd->buffer_size += RD_BUFFER_SIZE;
	}
	rd->il++;
	ft_insert_char(rd->input, c, rd->cp);
	TPUTS(CRS_SAVE);
	ft_putstr(&rd->input[rd->cp]);
	TPUTS(CRS_RESTORE);
	shell_next_cur_pos(rd);
}

void	shell_insert_string(t_reader *rd, char *string)
{
	if (string)
	{
		while (*string)
		{
			shell_insert_char(rd, *string);
			string++;
		}
	}
}
