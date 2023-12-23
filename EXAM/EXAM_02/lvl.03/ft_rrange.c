
#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	*range;
	int	i;
	int	step;
	int	n;

	i = 0;
	step = 1;
	n = end - start;
	if (n < 0)
		(n *= -1);
	n++;
	range = (int *)malloc(sizeof(int) * n);
	if (range)
	{
		if (start < end)
			step = -1;
		while (i < n)
		{
			range[i] = end;
			end = end + step;
			i++;
		}
	}
	return (range);
}
