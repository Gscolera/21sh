#include "shell.h"

void	shell_print_string(t_reader *rd, char *string)
{
	while (string && *string)
	{
		ft_putchar(*string);
		if (rd->crs.x < g_winsize.x)
		{
			rd->crs.x++;
		}
		else
		{
			rd->crs.x = 1;
			if (rd->crs.y < g_winsize.y)
			{
				rd->crs.y++;
			}
			else
			{
				rd->home.y--;
			}
		}
		string++;
	}
}
