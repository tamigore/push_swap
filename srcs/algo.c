/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <tamigore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:50:52 by user42            #+#    #+#             */
/*   Updated: 2021/11/09 11:35:03 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_sort(t_pile *lst)
{
	if (lst->a[0] == 0)
	{
		if (lst->a[1] == 2)
		{
			put_res(lst, &swap_a);
			put_res(lst, &revers_a);
		}
	}
	else if (lst->a[1] == 0)
	{
		if (lst->a[0] == 2)
			put_res(lst, &revers_a);
		else
			put_res(lst, &swap_a);
	}
	else
	{
		if (lst->a[0] == 2)
		{
			put_res(lst, &swap_a);
			put_res(lst, &rrevers_a);
		}
		else
			put_res(lst, &rrevers_a);
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

void	put_res(t_pile *lst, int (*fun)(t_pile *lst))
{
	int	i;

	if (lst->index == BUFFER_SIZE - 1)
	{
		i = 0;
		while (i < lst->index)
		{
			ft_putstr(revers_act(lst->res[i++]));
			ft_putstr("\n");
		}
		lst->index = 0;
		ft_bzero(lst->res, BUFFER_SIZE);
	}
	lst->res[lst->index++] = fun(lst);
}

void	solve(t_pile *lst)
{
	int	i;

	get_unified_pile(lst);
	if (check_all(lst))
		return ;
	if (lst->max_a <= 3)
		mini_sort(lst);
	else if (lst->max_a <= 30)
		sort(lst);
	else
		radix_sort(lst);
	if (lst->index < BUFFER_SIZE)
	{
		i = 0;
		while (i < lst->index)
		{
			ft_putstr(revers_act(lst->res[i++]));
			ft_putstr("\n");
		}
	}
}
