#include "shell.h"

void	shell_switch_flag(int flag)
{
	if (g_flags & flag)
	{
		g_flags &= ~flag;
	}
	else
	{
		g_flags |= flag;
	}
}
