#include "shell.h"

void	print_seq(char *seq)
{
	while (*seq)
	{
		ft_printf("%c ", *seq);
		seq++;
	}
	ft_printf("\n");
}

void	test(t_reader *rd)
{
	int fd = open("test", O_RDWR | O_CREAT, S_IWUSR | S_IRUSR);

	ft_putstr_fd("CP ", fd);
	ft_putnbr_fd(rd->cp, fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("CX ", fd);
	ft_putnbr_fd(rd->crs.x, fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("CY ", fd);
	ft_putnbr_fd(rd->crs.y, fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("IL ", fd);
	ft_putnbr_fd(rd->il, fd);
	ft_putchar_fd('\n', fd);
	close(fd);
}

void	shell_turn_off_options(int options)
{
	g_options &= ~options;
}

void shell_manage_escape(t_shell *sh, t_reader *rd, char *esc)
{
	if (ft_strequ(esc, KEY_LEFT) && !CURSOR_AT_HOME)
		shell_prev_cur_pos(rd);
	else if (ft_strequ(esc, KEY_RIGHT) && !CURSOR_IN_THE_END)
		shell_next_cur_pos(rd);
	else if (ft_strequ(esc, KEY_UP))
		shell_prev_command(sh, rd);
	else if (ft_strequ(esc, KEY_DOWN) && SCROLLING)
		shell_next_command(sh, rd);
	else if (ft_strequ(esc, KEY_HOME))
		shell_cursor_home(rd, *esc);
	else if (ft_strequ(esc, KEY_END))
		shell_cursor_home(rd, *esc);
	else if (ft_strequ(esc, KEY_DELETE) && !CURSOR_IN_THE_END)
		shell_delete_char(rd);
	else if (ft_strequ(esc, SHIFTED_RIGHT))
		shell_next_word(rd);
	else if (ft_strequ(esc, SHIFTED_LEFT))
		shell_prev_word(rd);
	else if (ft_strequ(esc, SHIFTED_UP))
		shell_prev_line(rd);
	else if (ft_strequ(esc, SHIFTED_DOWN))
		shell_next_line(rd);
	ft_strclr(rd->buffer);
}

void	shell_manage_key(t_shell *sh, t_reader *rd, char key)
{
	if (key == KEY_ESCAPE)
		shell_switch_option(READ | SHELL_ON);
	else if (key == KEY_BACKSPACE && CURSOR_AT_HOME)
	{
		shell_prev_cur_pos(rd);
		shell_delete_char(rd);
	}
	else if (key == KEY_ENTER)
	{
		shell_reset_history_ptr(sh);
		shell_deactivate_option(READ);
	}
	else if (key == CNTRL_R)
		shell_reversed_search(sh, rd);
}
