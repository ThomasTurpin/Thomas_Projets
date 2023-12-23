
#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	int		n;
	int		len;
	char	*result;

	if (nbr == -2147483648)
		return ("-2147483648\0");
	n = nbr;
	len = 0;
	if (nbr <= 0)
	{
		len++;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	if (nbr == 0)
	{
		result[0] = '0';
		return (result);
	}
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		result[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (result);
}
