#ifndef SETTINGS_H
# define SETTINGS_H

# define TPUTS(x)			tputs(rd->escape[x], fileno(stdout), ft_putchar)
# define CURSOR_AT_HOME		(rd->crs.x == rd->home.x && rd->crs.y == rd->home.y)
# define CURSOR_IN_THE_END	(rd->cp == rd->il)
# define IS_COMMENT(c)		(c[0] == '#')
# define LINE_EMPTY(line)	(line[0] == 0)
# define ESCAPE(c)			(c[0] == 27 && c[1] == 91)
# define SINGLE_QUOTE(c)	(c == 39)
# define DOUBLE_QUOTE(c)	(c == 34)
# define QUOTE(c)			(c == 39 || c == 34)
# define BACKSLASH(c)		(c == 92)
# define IS_SPACE(c)		(c == 9 || c == 32)
# define SEPARATOR(c)		(c == 124 || c == 59 || c == 38 || c == 0)
/*
**************SETTINGS*********************************************************
*/
# define CMD_MAX			131077
# define ENV_MAX			2048
# define PROMT_MAX			512
# define RD_BUFFER_SIZE		100
# define TEXT_DEFAULT_COLOR	"\033[0;38;2;255;240;175m"
# define PS1_DEFAULT_COLOR	"\033[1;4;38;2;54;214;6m"
# define PWD_DEFAULT_COLOR	"\033[1;4;38;2;255;0;0m"
# define SEARCH_COLOR_TRUE	"\033[1;38;2;172;0;252m"
# define SEARCH_COLOR_FALSE	"\033[1;38;2;255;0;0m"
# define END_OF_COLOR		"\033[0m"
# define INTV_BUFFER_SIZE	50
# define HISTSIZE			"500"
# define HISTFILESIZE		"2000"
# define HSFILE				".history"
# define SHELLRC			"shellrc"
/*
**************optionS************************************************************
*/
# define SHELL_ON			(1 << 0)
# define READ				(1 << 1)
# define SEARCH				(1 << 2)
# define CHOOSE				(1 << 3)
# define IE					(1 << 4)
# define SQT				(1 << 5)
# define DQT				(1 << 6)
# define SCROLL				(1 << 8)
# define HFO				(1 << 9)
# define CLO				(1 << 10)
# define MATCH				(1 << 11)
/*
**************COMMAND OPTIONS*************************************************
*/
# define PIPE				(1 << 0)
# define AND				(1 << 1)
# define OR					(1 << 2)
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
# define SHELLISON			(g_options & SHELL_ON)
# define READING			(g_options & READ)
# define SEARCHING			(g_options & SEARCH)
# define CHOOSING			(g_options & CHOOSE)
# define INPUT_IS_EMPTY		(g_options & IE)
# define SCROLLING			(g_options & SCROLL)
# define HISTORYFILE_OPENED	(g_options & HFO)
# define READING_HSFILE		(g_options & HFO)
# define IN_SINGLE_QUOTE	(g_options & SQT)
# define IN_DOUBLE_QUOTE	(g_options & DQT)
# define IN_QUOTES			(g_options & SQT || g_options & DQT)
# define MATCH_FOUND		(g_options & MATCH)
# define CMD_LEN_OVERFLOW	(g_options & CLO)
/*
*************KEYS**************************************************************
*/
# define KEY_BACKSPACE		127
# define KEY_ENTER			10
# define KEY_ESCAPE			27
# define CNTRL_R			18
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
