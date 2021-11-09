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
			revers_b(lst);
		lst->pos.y--;
		push_a(lst);
	}
	if (lst->b[0] == *min)
	{
		push_a(lst);
		revers_a(lst);
		if (lst->pos.check)
			rrevers_b(lst);
		(*min)++;
	}
	else if (lst->b[1] == *min)
	{
		swap_b(lst);
		push_a(lst);
		revers_a(lst);
		if (lst->pos.check)
			rrevers_b(lst);
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
				rrevers_b(lst);
				push_a(lst);
			}
			lst->pos.y--;
			rrevers_b(lst);
		}
		if (lst->b[lst->max_b - 1] == *min)
		{
			rrevers_b(lst);
			push_a(lst);
			revers_a(lst);
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
			rrevers_a(lst);
			swap_a(lst);
		}
		revers_a(lst);
		(*min)++;
	}
	else if (lst->a[1] == *min)
	{
		swap_a(lst);
		if (lst->pos.check)
		{
			rrevers_a(lst);
			swap_a(lst);
		}
		revers_a(lst);
		(*min)++;
	}
}

static void	track_a(t_pile *lst, int *min)
{
	while (lst->a[0] != *min && lst->a[1] != *min && lst->max_a)
	{
		if (lst->pos.y == 0 && lst->pos.check)
			revers_a(lst);
		push_b(lst);
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
