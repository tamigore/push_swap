/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <tamigore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:50:52 by user42            #+#    #+#             */
/*   Updated: 2021/08/10 22:31:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		get_unified_pile(t_pile *lst)
{
	int		nb;
	int		*uni;
	int		j;
	int		i;

	j = 0;
	uni = (int *)malloc(sizeof(int) * lst->max_a);
	if (!uni)
		exit_err(lst, "Memory Error");
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

int			check_all(t_pile *lst)
{
	int		i;

	i = 0;
	if (lst->max_b != 0)
		return (0);
	while (i < lst->max_a)
	{
		if (lst->a[i] != i)
			return (0);
		i++;
	}
	return(1);
}

int			check_pile(int *p, int max)
{
	int		i;
	int		j;

	i = 0;
	if (!p)
		return (0);
	j = p[0];
	while (i < max)
	{
		if (p[i] != j++)
			return (0);
		i++;
	}
	return(1);
}

/*
void		tri_mid(t_pile *lst)
{
}

void		tri_max(t_pile *lst)
{
}
*/
void		get_best_res(t_pile *lst)
{
	get_unified_pile(lst);
	if (check_all(lst))
	{
		printf("the pile is already in order");
		return ;
	}
	if (lst->max_a <= 5)
		tri_min(lst);
	else
		omg_tri(lst);
/*	else if (lst->max_a <= 100)
		tri_mid(lst);
	else
		tri_max(lst);
*/}
