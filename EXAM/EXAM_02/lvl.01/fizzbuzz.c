
#include <unistd.h>

void	print_nb(int nb)
{
	char	num [10] = "0123456789";

	if (nb > 9)
		print_nb (nb / 10);
	write (1, &num[nb % 10], 1);
}

int	main(void)
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		if (i % 15 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
			print_nb(i);
		i++;
		write(1, "\n", 1);
	}
}
