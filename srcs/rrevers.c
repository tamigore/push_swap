/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrevers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <tamigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:05:34 by tamigore          #+#    #+#             */
/*   Updated: 2021/10/24 17:05:50 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrevers_a(t_pile *lst)
{
	int	i;
	int	tmp;

	i = lst->max_a - 1;
	tmp = lst->a[i];
	while (i > 0)
	{
		lst->a[i] = lst->a[i - 1];
		i--;
	}
	lst->a[i] = tmp;
	ft_putstr("rra\n");
}

void	rrevers_b(t_pile *lst)
{
	int	i;
	int	tmp;

	i = lst->max_b - 1;
	tmp = lst->b[i];
	while (i > 0)
	{
		lst->b[i] = lst->b[i - 1];
		i--;
	}
	lst->b[i] = tmp;
	ft_putstr("rrb\n");
}

void	rrevers_r(t_pile *lst)
{
	rrevers_a(lst);
	rrevers_b(lst);
	ft_putstr("rrr\n");
}
