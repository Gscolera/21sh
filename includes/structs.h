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
	KEY_DELETE,
	TOTAL
};

struct 				s_coord
{
	size_t			x;
	size_t			y;
};

typedef struct		s_reader
{
	char			promt[PROMT_MAX];
	char			buffer[RD_BUFFER_SIZE + 1];
	char			*input;
	size_t			buffer_size;
	size_t			cp;
	size_t			il;
	char			*escape[TOTAL];
	struct s_coord	home;
	struct s_coord	crs;
}					t_reader;					

typedef struct		s_command
{
	char			line[CMD_MAX];
	char			**argv;
}					t_command;

typedef struct		s_shell
{
	char			**env;
	char			**intv;
	char			**argv;
	t_reader		rd;
	t_command		*cmd;
	struct termios	default_settings;
	struct termios	shell_settings;
}                   t_shell;

int					g_flags;
struct s_coord		g_winsize;

#endif
