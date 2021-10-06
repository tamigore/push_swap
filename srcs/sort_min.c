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
			ft_putstr(revers_act(rrevers_b(lst)));
//			lst->res[lst->index++] = rrevers_b(lst);
		if (lst->b[lst->max_b - 1] == *min)
		{
			ft_putstr(revers_act(rrevers_a(lst)));
			ft_putstr(revers_act(push_a(lst)));
			ft_putstr(revers_act(revers_a(lst)));
//			lst->res[lst->index++] = rrevers_b(lst);
//			lst->res[lst->index++] = push_a(lst);
//			lst->res[lst->index++] = revers_a(lst);
			(*min)++;
			return ;
		}
	}
	else
	{
		while(lst->b[0] != *min && lst->b[1] != *min)
			ft_putstr(revers_act(push_a(lst)));
//			lst->res[lst->index++] = push_a(lst);
		if (lst->b[0] == *min)
		{
			ft_putstr(revers_act(push_a(lst)));
			ft_putstr(revers_act(revers_a(lst)));
//			lst->res[lst->index++] = push_a(lst);
//			lst->res[lst->index++] = revers_a(lst);
			(*min)++;
			return ;
		}
		else if (lst->b[1] == *min && lst->max_b >= 2)
		{
			ft_putstr(revers_act(swap_b(lst)));
			ft_putstr(revers_act(push_a(lst)));
			ft_putstr(revers_act(revers_a(lst)));
//			lst->res[lst->index++] = swap_b(lst);
//			lst->res[lst->index++] = push_a(lst);
//			lst->res[lst->index++] = revers_a(lst);
			(*min)++;
			return ;
		}
	}
}

static void	m_track_a(t_pile *lst, int *min)
{
	while (lst->a[0] != *min && lst->a[1] != *min)
		ft_putstr(revers_act(push_b(lst)));
//		lst->res[lst->index++] = push_b(lst);
	if (lst->a[0] == *min)
	{
		ft_putstr(revers_act(revers_a(lst)));
//		lst->res[lst->index++] = revers_a(lst);
		(*min)++;
	}
	else if (lst->a[1] == *min)
	{
		ft_putstr(revers_act(swap_a(lst)));
		ft_putstr(revers_act(revers_a(lst)));
//		lst->res[lst->index++] = swap_a(lst);
//		lst->res[lst->index++] = revers_a(lst);
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
		track(lst, &min);
		if (lst->pos.x < lst->max_a)
			m_track_a(lst, &min);
		else
			m_track_b(lst, lst->pos.x, &min);
		if (min == max && check_all(lst))
			lst->valid = 1;
	}
}