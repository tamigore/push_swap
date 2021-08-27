
#include "push_swap.h"

int				track(t_pile *lst, int *min)
{
	int			i;

	i = 0;
	while (i < lst->max_a - *min)
	{
		if (lst->a[i] == *min)
		{
			if (i == lst->max_a - 1)
			{
				(*min)++;
				track(lst, min);
			}
			return (i);
		}
		i++;
	}
	i = 0;
	while (i < lst->max_b)
	{
		if (lst->b[i] == *min)
			return (i + lst->max_a);
		i++;
	}
	return (-1);
}

void			track_b(t_pile *lst, int pose, int *min, int max)
{
	if (pose > lst->max_b / 2)
	{
		while (lst->b[lst->max_b - 1] != *min)
			lst->res[lst->index++] = rrevers_b(lst);
		if (lst->b[lst->max_b - 1] == *min)
		{
			lst->res[lst->index++] = rrevers_b(lst);
			lst->res[lst->index++] = push_a(lst);
			lst->res[lst->index++] = revers_a(lst);
			(*min)++;
			return ;
		}
	}
	else
	{
		while(lst->b[0] != *min && lst->b[1] != *min)
		{
			if (lst->b[0] > *min + ((*min - max) / 2) && lst->max_b > 10)
				lst->res[lst->index++] = revers_b(lst);
			else
				lst->res[lst->index] = push_a(lst);
		}
		if (lst->b[0] == *min)
		{
			lst->res[lst->index++] = push_a(lst);
			lst->res[lst->index++] = revers_a(lst);
			(*min)++;
			return ;
		}
		else if (lst->b[1] == *min && lst->max_b >= 2)
		{
			lst->res[lst->index++] = swap_b(lst);
			lst->res[lst->index++] = push_a(lst);
			lst->res[lst->index++] = revers_a(lst);
			(*min)++;
			return ;
		}
	}
	min++;
}

void			track_a(t_pile *lst, int *min)
{
	while (lst->a[0] != *min && lst->a[1] != *min)
		lst->res[lst->index++] = push_b(lst);
	if (lst->a[0] == *min)
	{
		lst->res[lst->index++] = revers_a(lst);
		(*min)++;
	}
	else if (lst->a[1] == *min)
	{
		lst->res[lst->index++] = swap_a(lst);
		lst->res[lst->index++] = revers_a(lst);
		(*min)++;
	}
}

void			push_swap_sort(t_pile *lst)
{
	int			pose;
	int			min;
	int			max;

	min = 0;
	max = lst->max_a;
	while (lst->valid == 0)
	{
		pose = track(lst, &min);
		if (pose < lst->max_a)
			track_a(lst, &min);
		else
			track_b(lst, pose - lst->max_a, &min, max);
		if (min == max && check_all(lst))
			lst->valid = 1;
//		print_pile(lst);
	}
}