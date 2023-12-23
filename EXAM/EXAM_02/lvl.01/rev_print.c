#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argc == 2)
	{
		while (argv[1][j] != '\0')
			j++;
		while (argv[1][i])
		{
			write(1, &argv[1][--j], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
