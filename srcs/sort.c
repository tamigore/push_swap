/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:14:50 by tamigore          #+#    #+#             */
/*   Updated: 2021/10/24 17:14:55 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	track_b_up(t_pile *lst, int *min)
{
	while (lst->b[0] != *min && lst->b[1] != *min && lst->max_b)
	{
		if (lst->pos.y == 0 && lst->pos.check)
			put_res(lst, &revers_b);
		lst->pos.y--;
		put_res(lst, &push_a);
	}
	if (lst->b[0] == *min)
	{
		put_res(lst, &push_a);
		put_res(lst, &revers_a);
		if (lst->pos.check)
			put_res(lst, &rrevers_b);
		(*min)++;
	}
	else if (lst->b[1] == *min)
	{
		put_res(lst, &swap_b);
		put_res(lst, &push_a);
		put_res(lst, &revers_a);
		if (lst->pos.check)
			put_res(lst, &rrevers_b);
		(*min)++;
	}
}

static void	track_b(t_pile *lst, int *min)
{
	if (lst->pos.x > lst->max_b / 2)
	{
		while (lst->b[lst->max_b - 1] != *min && lst->max_b)
		{
			if (lst->pos.y == 0 && lst->pos.check)
			{
				put_res(lst, &rrevers_b);
				put_res(lst, &push_a);
			}
			lst->pos.y--;
			put_res(lst, &rrevers_b);
		}
		if (lst->b[lst->max_b - 1] == *min)
		{
			put_res(lst, &rrevers_b);
			put_res(lst, &push_a);
			put_res(lst, &revers_a);
			(*min)++;
		}
	}
	else
		track_b_up(lst, min);
}

static void	track_a_up(t_pile *lst, int *min)
{
	if (lst->a[0] == *min)
	{
		if (lst->pos.check)
		{
			put_res(lst, &rrevers_a);
			put_res(lst, &swap_a);
		}
		put_res(lst, &revers_a);
		(*min)++;
	}
	else if (lst->a[1] == *min)
	{
		put_res(lst, &swap_a);
		if (lst->pos.check)
		{
			put_res(lst, &rrevers_a);
			put_res(lst, &swap_a);
		}
		put_res(lst, &revers_a);
		(*min)++;
	}
}

static void	track_a(t_pile *lst, int *min)
{
	while (lst->a[0] != *min && lst->a[1] != *min && lst->max_a)
	{
		if (lst->pos.y == 0 && lst->pos.check)
			put_res(lst, &revers_a);
		put_res(lst, &push_b);
		lst->pos.y--;
	}
	track_a_up(lst, min);
}

void	sort(t_pile *lst)
{
	int	min;
	int	max;

	min = 0;
	max = lst->max_a;
	while (lst->valid == 0)
	{
		track(lst, &min, max);
		if (lst->pos.x < lst->max_a)
			track_a(lst, &min);
		else
		{
			lst->pos.x -= lst->max_a;
			track_b(lst, &min);
		}
		if (min == max && check_all(lst))
			lst->valid = 1;
	}
}
