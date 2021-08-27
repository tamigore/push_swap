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

static int		m_track(t_pile *lst, int *min)
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

static void	m_track_b(t_pile *lst, int pose, int *min)
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
			lst->res[lst->index++] = push_a(lst);
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
}

static void	m_track_a(t_pile *lst, int *min)
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

void			sort_min(t_pile *lst)
{
	int			pose;
	int			min;
	int			max;

	min = 0;
	max = lst->max_a;
	while (lst->valid == 0)
	{
		pose = m_track(lst, &min);
		if (pose < lst->max_a)
			m_track_a(lst, &min);
		else
			m_track_b(lst, pose - lst->max_a, &min);
		if (min == max && check_all(lst))
			lst->valid = 1;
	}
}