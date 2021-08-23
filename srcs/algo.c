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

int				get_placement(int *a, int nb, int max_a)
{
	int			i;

	i = 0;
	while (i < max_a && a[i] < nb)
		i++;
	return (i);
}

void		get_unified_pile(t_pile *lst)
{
	int		nb;
	int		*uni;
	int		j;
	int		i;

	j = 0;
	uni = (int *)malloc(sizeof(int) * lst->max_a);
	if (!uni)
		exit_err(lst);
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
		uni[j] = nb;
		j++;
	}
	i = 0;
	while (i < lst->max_a)
	{
		lst->a[i] = uni[i];
		i++;
	}
	free(uni);
}

void		solve(t_pile *lst)
{
	get_unified_pile(lst);
	if (check_all(lst))
		return ;
	if (lst->max_a <= 5)
		tri_min(lst);
	else
		omg_tri(lst);
/*	else if (lst->max_a <= 100)
		tri_mid(lst);
	else
		tri_max(lst);
*/}
