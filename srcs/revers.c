#include "push_swap.h"

int			revers_a(t_pile *lst)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = lst->a[0];
	while (i < lst->max_a - 1)
	{
		lst->a[i] = lst->a[i + 1];
		i++;
	}
	lst->a[i] = tmp;
	return (ra);
}

int			revers_b(t_pile *lst)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = lst->b[0];
	while (i < lst->max_b - 1)
	{
		lst->b[i] = lst->b[i + 1];
		i++;
	}
	lst->b[i] = tmp;
	return (rb);
}

int			revers_r(t_pile *lst)
{
	revers_a(lst);
	revers_b(lst);
	return (rr);
}

int			rrevers_a(t_pile *lst)
{
	int		i;
	int		tmp;

	i = lst->max_a - 1;
	tmp = lst->a[i];
	while (i > 0)
	{
		lst->a[i] = lst->a[i - 1];
		i--;
	}
	lst->a[i] = tmp;
	return (rra);
}

int			rrevers_b(t_pile *lst)
{
	int		i;
	int		tmp;

	i = lst->max_b - 1;
	tmp = lst->b[i];
	while (i > 0)
	{
		lst->b[i] = lst->b[i - 1];
		i--;
	}
	lst->b[i] = tmp;
	return (rrb);
}

int			rrevers_r(t_pile *lst)
{
	rrevers_a(lst);
	rrevers_b(lst);
	return (rrr);
}

