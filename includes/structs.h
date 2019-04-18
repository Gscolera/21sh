#ifndef STRUCTS_H
# define STRUCTS_H

# include <termios.h>
# include "settings.h"

enum				e_options
{
	CRS_RIGHT,
	CRS_LEFT,
	CRS_UP,
	CRS_DOWN,
	CRS_DEL,
	CRS_SAVE,
	CRS_RESTORE,
	CRS_CLEAR,
	SCREEN_CLEAR,
	KEY_RIGHT,
	KEY_LEFT,
	KEY_UP,
	KEY_DOWN,
	KEY_HOME,
	KEY_END,
	TOTAL_OPTIONS
};

enum				e_cursorpos
{
	HOME,
	CURRENT,
	END,
	TOTAL_POSITIONS
};

struct 				s_coord
{
	size_t			x;
	size_t			y;
};

typedef struct		s_reader
{
	char			buffer[ARG_MAX + 1];
	char			input[ARG_MAX + 1];
	size_t			cp;
	size_t			il;
}					t_reader;					

typedef struct		s_shell
{
	char			**env;
	char			**intv;
	char			**argv;
	char			*input;
	char			*escape[TOTAL_OPTIONS];
	struct s_coord	crs[TOTAL_POSITIONS];
	struct termios	default_settings;
	struct termios	shell_settings;
}                   t_shell;

int					g_flags;
struct s_coord		g_winsize;

#endif
