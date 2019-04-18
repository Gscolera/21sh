#ifndef SHELL_H
# define SHELL_H

# include "libft.h"
# include "ft_printf.h"
# include "structs.h"
# include <termcap.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <pwd.h>
# include <dirent.h>
# include <signal.h>
/*
***************ENV************************************************************
*/
void			shell_get_env(t_shell *sh);
void			shell_setenv(t_shell *sh, char *var, char *variable);
/*
****************READER*********************************************************
*/
void			shell_read_input(t_shell *sh);
void			shell_print_promt(t_shell *sh);
void			shell_insert_char(t_shell *sh, t_reader *rd, char c);
/*
****************LEXER**********************************************************
*/
void			shell_manage_input(t_shell *sh);
/*
****************EXECUTER*******************************************************
*/
void			shell_execute_command(t_shell *sh);
void			shell_run_binary(t_shell *sh);
/*
*****************BUILTIN*******************************************************
*/
int				shell_print_env(t_shell *sh);
int				shell_change_dir(t_shell *sh);
/*
****************TOOLS**********************************************************
*/
int				shell_open(t_shell *sh);
void			shell_close(t_shell *sh);
void			shell_switch_flag(int flag);
int				shell_print_error(int errno);
char			*shell_getvalue(t_shell *sh, char *variable);
void			shell_get_cursor_position(struct s_coord *cursor);
void			shell_get_winsize(void);
void			shell_set_bg_color(t_shell *sh);
void			shell_set_bg_to_line(t_shell *sh);
/*
*****************CURSOR MOTION************************************************* 
*/
void			shell_mvcl(t_shell *sh, t_reader *rd);
void			shell_mvcr(t_shell *sh, t_reader *rd);
void			shell_mvcu(t_shell *sh, t_reader *rd);
void			shell_mvcd(t_shell *sh, t_reader *rd);
void			shell_mvche(t_shell *sh, t_reader *rd, char direction);
void			shell_goto(t_shell *sh, size_t x, size_t y);

#endif
