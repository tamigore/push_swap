/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <tamigore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:05:24 by user42            #+#    #+#             */
/*   Updated: 2021/08/10 22:25:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	m_track_b(t_pile *lst, int pos, int *min)
{
	if (pos > lst->max_b / 2)
	{
		while (lst->b[lst->max_b - 1] != *min)
			put_res(lst, &rrevers_b);
		if (lst->b[lst->max_b - 1] == *min)
		{
			put_res(lst, &rrevers_a);
			put_res(lst, &push_a);
			put_res(lst, &revers_a);
			(*min)++;
			return ;
		}
	}
	else
	{
		while(lst->b[0] != *min && lst->b[1] != *min)
			put_res(lst, &push_a);
		if (lst->b[0] == *min)
		{
			put_res(lst, &push_a);
			put_res(lst, &revers_a);
			(*min)++;
			return ;
		}
		else if (lst->max_b >= 2 && lst->b[1] == *min)
		{
			put_res(lst, &swap_b);
			put_res(lst, &push_a);
			put_res(lst, &revers_a);
			(*min)++;
			return ;
		}
	}
}

static void	m_track_a(t_pile *lst, int *min)
{
	while (lst->a[0] != *min && lst->a[1] != *min)
		put_res(lst, &push_b);
	if (lst->a[0] == *min)
	{
		put_res(lst, &revers_a);
		(*min)++;
	}
	else if (lst->a[1] == *min)
	{
		put_res(lst, &swap_a);
		put_res(lst, &revers_a);
		(*min)++;
	}
}

void			sort_min(t_pile *lst)
{
	int			min;
	int			max;

	min = 0;
	max = lst->max_a;
	while (lst->valid == 0)
	{
		track(lst, &min, max);
		if (lst->pos.x < lst->max_a)
			m_track_a(lst, &min);
		else
			m_track_b(lst, lst->pos.x - lst->max_a, &min);
		if (min == max && check_all(lst))
			lst->valid = 1;
	}
}