#ifndef SETTINGS_H
# define SETTINGS_H

# define ACTION(x)			tputs(sh->escape[x], fileno(stdout), ft_putchar)
# define ESCAPE(b)			(b[0] == 27 && b[1] == 91)
/*
**************SETTINGS*********************************************************
*/
# define BG_DEFAULT_COLOR	"\033[48;2;48;10;36m"
# define TEXT_DEFAULT_COLOR	"\033[0;38;2;255;240;175m"
# define PS1_DEFAULT_COLOR	"\033[1;4;38;2;54;214;6m"
# define PWD_DEFAULT_COLOR	"\033[1;4;38;2;255;0;0m"
# define INTV_BUFFER_SIZE	50
# define HISTSIZE			500
# define HISTFILESIZE		1000
/*
**************FLAGS************************************************************
*/
# define SHELL_ON			(1 << 0)
# define READ				(1 << 1)
# define SEARCH				(1 << 2)
# define CHOOSE				(1 << 3)
/*
**************ERRORS***********************************************************
*/
# define SH_MALLOC_ERROR	(1 << 0)
# define SH_TERM_NOT_DEF	(1 << 1)
# define SH_TERM_NO_ACCESS	(1 << 2)
# define SH_FORK_ERROR		(1 << 3)
# define SH_VAR_NOT_SET		(1 << 4)
/*
 ************TERMINAL MODES****************************************************
 */
# define SHELLISON			(g_flags & SHELL_ON)
# define READING			(g_flags & READ)
# define SEARCHING			(g_flags & SEARCH)
# define CHOOSING			(g_flags & CHOOSE)
/*
*************KEYS**************************************************************
*/
# define KEY_BACKSPACE		127
# define KEY_ENTER			10
# define KEY_ESCAPE			27

# ifdef __linux__
#  define ARG_MAX			4096
# endif
#endif
