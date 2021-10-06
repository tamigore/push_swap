#include "../includes/push_swap.h"

static long long int		push_swap_atoi(int *a, char *str)
{
	int						i;
	int						neg;
	int						test;
	unsigned long long int	nb;

	i = 0;
	neg = 1;
	nb = 0;
	while ((str[i] <= '\r' && str[i] >= '\r') || str[i] == ' ')
		i++;
	test = i;
	while (str[test])
	{
		if ((str[test] < '0' || str[test] > '9') && str[test] != '-' && str[test] != '+')
		{
			free(a);
			exit(EXIT_FAILURE);
		}
		test++;
	}
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + str[i++] - '0';
	if ((long long)(nb * neg) > 2147483647 || (long long)(nb * neg) < -2147483648)
	{
		free(a);
		exit(EXIT_FAILURE);
	}
	return (nb * neg);
}

static int		*init_a(int ac, char **av)
{
	int			*a;
	int			i;
	int			j;

	a = (int *)malloc(sizeof(int) * (ac - 1));
	if (!a)
		return (-1);
	i = 0;
	while (i < ac - 1)
	{
		a[i] = push_swap_atoi(a, av[i + 1]);
		i++;
	}
	i = 0;
	while (i < ac - 1)
	{
		j = 0;
		while (j < ac - 1)
		{
			if ((a[i] == a[j]) && i != j)
			{
				free(a);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	return (a);
}

int     	main(int ac, char **av)
{
	int 	*a;
	int		*b;
	if (ac < 2)
		return (0);
	a = init_a(ac, av);
	b = (int *)malloc(sizeof(int) * (ac - 1));
	return (0);
}