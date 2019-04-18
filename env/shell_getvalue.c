#include "shell.h"

char	*shell_getvalue(t_shell *sh, char *variable)
{
	int		i;
	size_t	len;

	if (!(len = ft_strlen(variable)))
		return (NULL);
	i = -1;
	while (sh->env && sh->env[++i])
	{
		if (ft_strnequ(sh->env[i], variable, len) && sh->env[i][len] == '=')
			return (&sh->env[i][len + 1]);
	}
	i = -1;
	while (sh->intv && sh->intv[++i])
	{
		if (ft_strnequ(sh->intv[i], variable, len) && sh->intv[i][len] == '=')
			return (&sh->intv[i][len + 1]);

	}
	return (NULL);
}
