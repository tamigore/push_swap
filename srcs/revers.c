/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <tamigore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:56:02 by user42            #+#    #+#             */
/*   Updated: 2021/08/10 17:56:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	revers_a(t_pile *lst)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = lst->a[0];
	while (i < lst->max_a - 1)
	{
		lst->a[i] = lst->a[i + 1];
		i++;
	}
	lst->a[i] = tmp;
	return (ra);
}

int	revers_b(t_pile *lst)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = lst->b[0];
	while (i < lst->max_b - 1)
	{
		lst->b[i] = lst->b[i + 1];
		i++;
	}
	lst->b[i] = tmp;
	return (rb);
}

int	revers_r(t_pile *lst)
{
	revers_a(lst);
	revers_b(lst);
	return (rr);
}
