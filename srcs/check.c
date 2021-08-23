/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <tamigore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:45:59 by user42            #+#    #+#             */
/*   Updated: 2021/08/13 21:42:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	j = p[0];
	while (i < max)
	{
		if (p[i] != j++)
			return (0);
		i++;
	}
	return(1);
}

int			check_revers_pile(int *p, int max)
{
	int		j;

	j = p[max];
	while (max > 0)
	{
		if (p[max] != j--)
			return (0);
		max--;
	}
	return(1);
}