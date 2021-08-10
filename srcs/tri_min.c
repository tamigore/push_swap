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

static	void	tri_3(t_pile *lst)
{
	if (lst->a[0] > lst->a[1] && lst->a[1] > lst->a[2])
	{
		lst->res[lst->index++] = swap_a(lst);
		lst->res[lst->index++] = rrevers_a(lst);
	}
	else if (lst->a[0] < lst->a[2] && lst->a[2] < lst->a[1])
	{
		lst->res[lst->index++] = swap_a(lst);
		lst->res[lst->index++] = revers_a(lst);
	}  
	else if (lst->a[1] < lst->a[2] && lst->a[2] < lst->a[0])
	{
		lst->res[lst->index++] = revers_a(lst);
	}
	else if (lst->a[1] < lst->a[0] && lst->a[0] < lst->a[2])
	{
		lst->res[lst->index++] = swap_a(lst);
	}
	else if (lst->a[0] > lst->a[2] && lst->a[0] < lst->a[1])
		lst->res[lst->index++] = rrevers_a(lst);
}

static	void	insert_nb4(t_pile *lst, int i)
{
	if (i == 0)
		lst->res[lst->index++] = push_b(lst);
	else if (i == 1)
	{
		lst->res[lst->index++] = push_b(lst);
		lst->res[lst->index++] = swap_a(lst);
	}
	else if (i == 2)
	{
		lst->res[lst->index++] = rrevers_a(lst);
		lst->res[lst->index++] = push_b(lst);
		lst->res[lst->index++] = swap_a(lst);
		lst->res[lst->index++] = revers_a(lst);
	}
	else
	{
		lst->res[lst->index++] = push_b(lst);
		lst->res[lst->index++] = revers_a(lst);
	}
}

static	void	insert_nb5(t_pile *lst, int i)
{
	if (i == 0)
		lst->res[lst->index++] = push_b(lst);
	else if (i == 1)
	{
		lst->res[lst->index++] = push_b(lst);
		lst->res[lst->index++] = swap_a(lst);
	}
	else if (i == 2)
	{
		lst->res[lst->index++] = rrevers_a(lst);
		lst->res[lst->index++] = push_b(lst);
		lst->res[lst->index++] = swap_a(lst);
		lst->res[lst->index++] = revers_a(lst);
	}
	else if (i == 3)
	{
		lst->res[lst->index++] = rrevers_a(lst);
		lst->res[lst->index++] = push_b(lst);
		lst->res[lst->index++] = revers_a(lst);
		lst->res[lst->index++] = revers_a(lst);
	}
	else
	{
		lst->res[lst->index++] = push_b(lst);
		lst->res[lst->index++] = revers_a(lst);
	}
}


int				get_placement(t_pile *lst, int nb)
{
	int			i;

	i = 0;
	while (lst->a[i] < lst->max_a && lst->a[i] < nb)
		i++;
	return (i);
}

void			tri_min(t_pile *lst)
{
	if (lst->max_a == 2)
	{
		lst->res[lst->index++] = swap_a(lst);
		return ;
	}
	else if (lst->max_a == 3)
	{
		tri_3(lst);
		return ;
	}
	else if (lst->max_a == 4)
	{
		lst->res[lst->index++] = push_a(lst);
		tri_3(lst);
		insert_nb4(lst, get_placement(lst, lst->b[0]));
		return ;
	}
	lst->res[lst->index++] = push_a(lst);
	lst->res[lst->index++] = push_a(lst);
	tri_3(lst);
	insert_nb4(lst, get_placement(lst, lst->b[0]));
	insert_nb5(lst, get_placement(lst, lst->b[0]));
}
