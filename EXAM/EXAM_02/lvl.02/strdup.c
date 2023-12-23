
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*str;
	int		len;

	len = 0;
	i = 0;
	while (src[i])
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (str != NULL)
	{
		while (src[i])
		{
			str[i] = src[i];
			i++;
		}
	}
	return (str);
}
