#ifndef STRUCTS_H
# define STRUCTS_H

# include <termios.h>
# include "settings.h"

enum					e_options
{
	CRS_RIGHT,
	CRS_LEFT,
	CRS_UP,
	CRS_NS,
	CRS_DEL,
	CRS_SAVE,
	CRS_RESTORE,
	CRS_CLEAR,
	SCREEN_CLEAR,
	CRS_DOWN,
	TOTAL
};

struct 					s_cursor
{
	size_t				x;
	size_t				y;
};

typedef struct			s_reader
{
	char				promt[PROMT_MAX];
	char				buffer[RD_BUFFER_SIZE + 1];
	char				*input;
	size_t				buffer_size;
	size_t				cp;
	size_t				il;
	char				*escape[TOTAL];
	struct s_cursor		home;
	struct s_cursor		crs;
}						t_reader;					

typedef struct			s_command
{
	char				line[CMD_MAX];
	char				**argv;
	struct s_command	*next;
}						t_command;

typedef struct			s_buffer
{
	char				*data;
	size_t				id;
	struct s_buffer		*prev;
	struct s_buffer		*next;
}						t_buffer;

typedef struct			s_request
{
	char				line[CMD_MAX];
	char				*match;
	size_t				len;
	size_t				cp;
}						t_request;

typedef struct			s_shell
{
	char				**env;
	char				**intv;
	char				**argv;
	int					fd;
	t_reader			rd;
	t_command			*cmd;
	t_buffer			*history;
	t_buffer			*hist_ptr;
	t_buffer			*hist_last;
	struct termios		default_settings;
	struct termios		shell_settings;
}                   	t_shell;

int						g_flags;
struct s_cursor			g_winsize;

#endif
