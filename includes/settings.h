#ifndef SETTINGS_H
# define SETTINGS_H

# define TPUTS(x)			tputs(rd->escape[x], fileno(stdout), ft_putchar)
# define ESCAPE(b)			(b[0] == 27 && b[1] == 91)
/*
**************SETTINGS*********************************************************
*/
# define CMD_MAX			131077
# define PROMT_MAX			512
# define RD_BUFFER_SIZE		100
# define TEXT_DEFAULT_COLOR	"\033[0;38;2;255;240;175m"
# define PS1_DEFAULT_COLOR	"\033[1;4;38;2;54;214;6m"
# define PWD_DEFAULT_COLOR	"\033[1;4;38;2;255;0;0m"
# define INTV_BUFFER_SIZE	50
# define HISTSIZE			"100"
# define HISTFILESIZE		"500"
# define HSFILE				".history"
# define SHELLRC			"shellrc"
/*
**************FLAGS************************************************************
*/
# define SHELL_ON			(1 << 0)
# define READ				(1 << 1)
# define SEARCH				(1 << 2)
# define CHOOSE				(1 << 3)
# define SQT				(1 << 5)
# define DQT				(1 << 6)
# define NS					(1 << 7)
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
# define NEW_STRING			(g_flags & NS)
/*
*************KEYS**************************************************************
*/
# define KEY_BACKSPACE		127
# define KEY_ENTER			10
# define KEY_ESCAPE			27
# define KEY_RIGHT			"C"
# define KEY_LEFT			"D"
# define KEY_UP				"A"
# define KEY_DOWN			"B"
# define KEY_HOME			"H"
# define KEY_END			"F"
# define KEY_DELETE			"3~"
# define SHIFTED_RIGHT		"1;2C"
# define SHIFTED_LEFT		"1;2D"
# define SHIFTED_UP			"1;2A"
# define SHIFTED_DOWN		"1;2B"

#endif
