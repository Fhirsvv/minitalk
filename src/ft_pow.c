#include <stdio.h>
#include <math.h>

int ft_pow (int nb, int exp)
{
	if (exp == 0)
		return (1);
	else if (exp == 1)
		return (nb);
	else
		return (nb * ft_pow(nb, exp - 1));
}

int main ()
{
	printf("ft_pow: %d\n", ft_pow(2, 12));
	printf("ft_pow: %f\n", pow(2, 12));
	return 0;
}