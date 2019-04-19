#include "shell.h"

static void	shell_get_escape_sequences(t_reader *rd)
{
	rd->escape[CRS_RIGHT] = tgetstr("nd", NULL);
	rd->escape[CRS_LEFT] = tgetstr("le", NULL);
	rd->escape[CRS_UP] = tgetstr("up", NULL);
	rd->escape[CRS_DOWN] = tgetstr("do", NULL);
	rd->escape[CRS_DEL] = tgetstr("dc", NULL);
	rd->escape[CRS_CLEAR] = tgetstr("cd", NULL);
	rd->escape[CRS_SAVE] = tgetstr("sc", NULL);
	rd->escape[CRS_RESTORE] = tgetstr("rc", NULL);
	rd->escape[SCREEN_CLEAR] = tgetstr("cl", NULL);
	rd->escape[KEY_RIGHT] = "C";
	rd->escape[KEY_LEFT] = "D";
	rd->escape[KEY_UP] = "A";
	rd->escape[KEY_DOWN] = "B";
	rd->escape[KEY_HOME] = "H";
	rd->escape[KEY_END] = "F";
	rd->escape[KEY_DELETE] = "3~";
}

static void	shell_get_terminal_mode(t_shell *sh)
{
	tcgetattr(fileno(stdout), &sh->default_settings);
	sh->shell_settings = sh->default_settings;
	sh->shell_settings = sh->default_settings;
	sh->shell_settings.c_lflag &= ~(ECHO | ICANON);
	sh->shell_settings.c_cc[VMIN] = 0;
	sh->shell_settings.c_cc[VTIME] = 1;
}

int			shell_open(t_shell *sh)
{
	int				set_term;

	ft_memset(sh, 0, sizeof(t_shell));
	shell_get_env(sh);
	if (!sh->env || !sh->intv)
		exit(shell_print_error(SH_MALLOC_ERROR));
	shell_get_terminal_mode(sh);
	set_term = tgetent(NULL, shell_getvalue(sh, "TERM"));
	if (!set_term)
		exit(shell_print_error(SH_TERM_NOT_DEF));
	else if (set_term == -1)
		exit(shell_print_error(SH_TERM_NO_ACCESS));
	shell_get_escape_sequences(&sh->rd);
	shell_get_winsize();
	shell_set_bg_color(sh, &sh->rd);
	shell_switch_flag(SHELL_ON);
	return (0);
}
