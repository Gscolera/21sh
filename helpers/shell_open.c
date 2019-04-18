#include "shell.h"

static void	shell_get_escape_sequences(t_shell *sh)
{
	sh->escape[CRS_RIGHT] = tgetstr("nd", NULL);
	sh->escape[CRS_LEFT] = tgetstr("le", NULL);
	sh->escape[CRS_UP] = tgetstr("up", NULL);
	sh->escape[CRS_DOWN] = tgetstr("do", NULL);
	sh->escape[CRS_DEL] = tgetstr("dc", NULL);
	sh->escape[CRS_CLEAR] = tgetstr("cd", NULL);
	sh->escape[CRS_SAVE] = tgetstr("sc", NULL);
	sh->escape[CRS_RESTORE] = tgetstr("rc", NULL);
	sh->escape[SCREEN_CLEAR] = tgetstr("cl", NULL);
	sh->escape[KEY_RIGHT] = "C";
	sh->escape[KEY_LEFT] = "D";
	sh->escape[KEY_UP] = "A";
	sh->escape[KEY_DOWN] = "B";
	sh->escape[KEY_HOME] = "H";
	sh->escape[KEY_END] = "F";
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
	shell_get_escape_sequences(sh);
	shell_get_winsize();
	shell_set_bg_color(sh);
	shell_switch_flag(SHELL_ON);
	return (0);
}
