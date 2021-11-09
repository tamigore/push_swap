/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <tamigore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:50:52 by user42            #+#    #+#             */
/*   Updated: 2021/11/09 11:42:02 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_sort(t_pile *lst)
{
	if (lst->a[0] == 0)
	{
		if (lst->a[1] == 2)
		{
			swap_a(lst);
			revers_a(lst);
		}
	}
	else if (lst->a[1] == 0)
	{
		if (lst->a[0] == 2)
			revers_a(lst);
		else
			swap_a(lst);
	}
	else
	{
		if (lst->a[0] == 2)
		{
			swap_a(lst);
			rrevers_a(lst);
		}
		else
			rrevers_a(lst);
	}
}

void	get_unified_pile(t_pile *lst)
{
	int	nb;
	int	j;
	int	i;

	j = 0;
	while (j < lst->max_a)
	{
		i = 0;
		nb = 0;
		while (i < lst->max_a)
		{
			if (lst->a[i] < lst->a[j])
				nb++;
			i++;
		}
		lst->b[j] = nb;
		j++;
	}
	i = 0;
	while (i < lst->max_a)
	{
		lst->a[i] = lst->b[i];
		i++;
	}
	ft_bzero(lst->b, lst->max_a);
}

void	solve(t_pile *lst)
{
	get_unified_pile(lst);
	if (check_all(lst))
		return ;
	if (lst->max_a <= 3)
		mini_sort(lst);
	else if (lst->max_a <= 30)
		sort(lst);
	else
		radix_sort(lst);
}
