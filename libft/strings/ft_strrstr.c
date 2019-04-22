#include "libft.h"

char	*ft_strrstr(char *string, char *srch)
{
	size_t	len;
	char	*ptr;

	if (!string || !srch)
		return (NULL);
	ptr = string + ft_strlen(string);
	len = ft_strlen(srch);
	while (ptr != string)
	{
		if (ft_strnequ(ptr, srch, len))
			return (string);
		ptr--;
	}
	return (NULL);
}
