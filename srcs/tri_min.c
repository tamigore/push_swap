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

int				nb_coup(int *a, int i, int max, int sens)
{
	int			nb;

	nb = 1;
	if (sens > 0)
	{
		while (i > 0)
			nb++;
	}
	else
	{
		
	}
	return (-1);
}

void			tri_min(t_pile *lst)
{
	int		i;
	int		j;
	int		res_i;
	int		res_j;

	i = 0;
	j = lst->max_a - 1;
	res_i = 0;
	res_j = 0;
	while (i < lst->max_a / 2)
	{
		if (lst->a[i] != i)
		{
			res_i = nb_coup(lst->a, i, lst->max_a, 1);
			break ;
		}
		i++;
	}
	while (j >= lst->max_a / 2)
	{
		if (lst->a[j] != j)
		{
			res_i = nb_coup(lst->a, i, lst->max_a, -1);
			break ;
		}
		i++;
	}
	res_i = res_j > res_i ? res_i : res_j;
	if (a[i])

/*
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
		insert_nb4(lst, get_placement(lst->a, lst->b[0], lst->max_a));
		return ;
	}
	lst->res[lst->index++] = push_a(lst);
	lst->res[lst->index++] = push_a(lst);
	tri_3(lst);
	insert_nb4(lst, get_placement(lst->a, lst->b[0], lst->max_a));
	insert_nb5(lst, get_placement(lst->a, lst->b[0], 
}
