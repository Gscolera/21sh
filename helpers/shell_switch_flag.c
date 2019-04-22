#include "shell.h"

void	shell_switch_flag(int flag)
{
	if (g_flags & flag)
	{
		TURN_OFF(flag);
	}
	else
	{
		TURN_ON(flag);
	}
}


