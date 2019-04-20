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
void			shell_read_input(t_shell *sh, t_reader *rd);
void			shell_print_promt(t_shell *sh, t_reader *rd);
void			shell_insert_char(t_reader *rd, char c);
void			shell_insert_string(t_reader *rd, char *string);
void			shell_delete_char(t_reader *rd);
void			shell_next_cur_pos(t_reader *rd);
void			shell_prev_cur_pos(t_reader *rd);
void			shell_cursor_home(t_reader *rd, char direction);
void			shell_next_word(t_reader *rd);
void			shell_prev_word(t_reader *rd);
void			shell_next_line(t_reader *rd);
void			shell_prev_line(t_reader *rd);
/*
****************LEXER**********************************************************
*/
void			shell_manage_input(t_shell *sh);
void			shell_get_commands(t_shell *sh);
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
int				shell_unset_env(t_shell *sh);
/*
*****************HISTORY********************************************************
*/
void			shell_save_input(t_shell *sh, char *input);
void			shell_save_to_tmp_buffer(t_shell *sh, char *input);
int				shell_save_history(t_shell *sh);
void			shell_prev_command(t_shell *sh, t_reader *rd);
void			shell_next_command(t_shell *sh, t_reader *rd);
void			shell_reset_history_ptr(t_shell *sh);
/*
****************HELPERS**********************************************************
*/
int				shell_open(t_shell *sh);
void			shell_close(t_shell *sh);
void			shell_switch_flag(int flag);
int				shell_print_error(int errno);
char			*shell_getvalue(t_shell *sh, char *variable);
void			shell_get_cursor_position(struct s_cursor *cursor);
void			shell_get_winsize(void);
void			shell_clear_input(t_reader *rd);
void			shell_free_buffer(t_buffer *buffer);
/*
*****************CURSOR MOTION************************************************* 
*/
void			cursor_right(t_reader *rd);
void			cursor_left(t_reader *rd);
void			cursor_down(t_reader *rd);
void			cursor_up(t_reader *rd);
void			cursor_goto(t_reader *rd, size_t x, size_t y);

#endif
