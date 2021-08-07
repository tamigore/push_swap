#include "push_swap.h"

void		get_unified_pile(t_pile *lst)
{
	int		nb;
	int		*uni;
	int		j;
	int		i;

	j = 0;
	uni = (int *)malloc(sizeof(int) * lst->max_a);
	if (!uni)
		exit_err(lst, "Memory Error");
	while (j < lst->max_a)
	{
		i = 0;
		nb = 0;
		while (i < lst->max_a)
		{
			if (lst->a[i] < lst->a[j])
				nb++;
			i++;
		}
		uni[j] = nb;
		j++;
	}
	i = 0;
	while (i < lst->max_a)
	{
		lst->a[i] = uni[i];
		i++;
	}
	free(uni);
}

int			check(t_pile *lst)
{
	int		i;

	i = 0;
	if (lst->max_b != 0)
		return (0);
	while (i < lst->max_a)
	{
		if (lst->a[i] != i)
			return (0);
		i++;
	}
	return(1);
}

void		tri_min(t_pile *lst)
{
	if (check(lst))
		return ;
	if (lst->max_a == 2)
	{
		lst->res[lst->index++] = swap_a(lst);
		return ;
	}
	else if (lst->max_a == 3)
	{
		
	}
	lst->res[lst->index++] = push_a(lst);
	lst->res[lst->index++] = push_a(lst);
	if ()
}

void		tri_mid(t_pile *lst)
{
}

void		tri_max(t_pile *lst)
{
}

void		get_best_res(t_pile *lst)
{
	get_unified_pile(lst);
	if (lst->max_a <= 5)
		tri_min(lst);
	else if (lst->max_a <= 100)
		tri_mid(lst);
	else
		tri_max(lst);
}
