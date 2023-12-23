

int	max(int *tab, unsigned int len)
{
	unsigned int	result;
	unsigned int	i;

	if (len == 0)
		return (0);
	i = 0;
	result = tab[i];
	while (i < len)
	{
		if (result < tab[i])
		{
			result = tab[i];
		}
		i++;
	}
	return (result);
}
