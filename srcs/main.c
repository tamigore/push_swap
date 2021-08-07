#include "push_swap.h"

void		exit_err(void *ptr, char *str)
{
	if (ptr)
		free(ptr);
	printf("%s", str);
}

t_pile		*init_pile(int ac, char **av)
{
	t_pile	*lst;
	int		i;

	lst = (t_pile *)malloc(sizeof(t_pile));
	if (!lst)
		exit_err(NULL, "Memory Error");
	lst->valid = 0;
	lst->max_a = ac - 1;
	lst->max_b = 0;
	lst->index = 0;
	lst->a = (int *)malloc(sizeof(int) * lst->max_a);
	if (!lst->a)
		exit_err(lst, "Memory Error");
	i = 0;
	while (i < ac - 1)
	{
		lst->a[i] = ft_atoi(av[i + 1]);
		i++;
	}
	lst->b = (int *)malloc(sizeof(int) * lst->max_a);
	if (!lst->b)
	{
		free(lst->a);
		exit_err(lst, "Memory Error");
	}
	lst->res = (int *)malloc(sizeof(int) * lst->max_a);
	if (!lst->res)
	{
		free(lst->b);
		free(lst->a);
		exit_err(lst, "Memory Error");
	}
	return (lst);
}

void		print_pile(t_pile *lst)
{
	int		i;

	i = 0;
	if (!lst)
		exit_err(NULL, "Error : no pile to print");
	printf("Valid : %d\nMax_a : %d\nMax_b : %d\n", lst->valid, lst->max_a, lst->max_b);
	while (i < lst->max_a)
	{
		printf("pile a[%d] : %d\n", i, lst->a[i]);
		i++;
	}
	i = 0;
	while (i < lst->max_b)
	{
		printf("pile b[%d] : %d\n", i, lst->b[i]);
		i++;
	}
	i = 0;
	while (i < lst->index)
	{
		printf("res[%d] : %d\n", i, lst->res[i]);
		i++;
	}
}

int			main(int ac, char **av)
{
	t_pile	*lst;

	if (ac < 2)
		exit_err(NULL, "Error : Not enough arguments.");
	lst = init_pile(ac, av);
	print_pile(lst);
	get_best_res(lst);
	print_pile(lst);
	return (0);
}
