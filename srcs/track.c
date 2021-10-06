#include "push_swap.h"

void		track(t_pile *lst, int *min)
{
	int			i;

	i = 0;
	lst->pos.check = 0;
	while (i < lst->max_a - *min)
	{
		if (lst->a[i] == *min)
		{
			if (i == lst->max_a - 1)
			{
				(*min)++;
				track(lst, min);
			}
			lst->pos.x = i;
		}
		if (lst->a[i] == *min + 1)
			lst->pos.y = i;
		i++;
	}
	i = 0;
	while (i < lst->max_b)
	{
		if (lst->b[i] == *min)
			lst->pos.x = i + lst->max_a;
		else if (lst->b[i] == *min + 1)
			lst->pos.y = i + lst->max_a;
		i++;
	}
	if (lst->pos.x < lst->max_a)
	{
		if (lst->pos.y < lst->pos.x)
			lst->pos.check = 1;
	}
	else
	{
		if (lst->pos.x - lst->max_a < lst->max_b / 2)
		{
			if (lst->pos.y < lst->pos.x)
			{
				lst->pos.check = 1;
				lst->pos.y -= lst->max_a;
			}
		}
		else
		{
			if (lst->pos.y > lst->pos.x)
			{
				lst->pos.check = 1;
				lst->pos.y = (lst->max_b - 1) - (lst->pos.y - lst->max_a);
			}
		}
	}
	if (lst->max_b == 0 && *min == lst->max_a - 1)
		lst->pos.check = 0;
}