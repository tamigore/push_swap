/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <tamigore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:50:52 by user42            #+#    #+#             */
/*   Updated: 2021/08/23 12:22:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		get_unified_pile(t_pile *lst)
{
	int		nb;
	int		j;
	int		i;

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
	ft_memset(lst->b, 0, lst->max_a);
}

void		put_res(t_pile *lst, int (*fun)(t_pile *lst))
{
	int		i;

	if (lst->index == BUFFER_SIZE)
	{
		i = 0;
		while (i <= lst->index)
		{
			ft_putstr(revers_act(lst->res[i++]));
			ft_putstr("\n");
		}
		lst->index = 0;
	}
	else
		lst->res[lst->index++] = fun(lst);
}

/*
int			get_opti(t_pile *lst, int x, int y)
{
	int		i;
	int		j;
	int		nb;

	nb = 0;
	while ()
}
*/
void		solve(t_pile *lst)
{
	ft_putstr("no\n");
	get_unified_pile(lst);
	ft_putstr("yes\n");
	if (check_all(lst))
		return ;
	if (lst->max_a <= 10)
		sort_min(lst);
	else
		sort(lst);
}
