/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <tamigore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:56:08 by user42            #+#    #+#             */
/*   Updated: 2021/08/10 17:56:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_pile *lst)
{
	int	tmp;

	tmp = lst->a[0];
	lst->a[0] = lst->a[1];
	lst->a[1] = tmp;
	ft_putstr("sa\n");
}

void	swap_b(t_pile *lst)
{
	int	tmp;

	tmp = lst->b[0];
	lst->b[0] = lst->b[1];
	lst->b[1] = tmp;
	ft_putstr("sb\n");
}

void	swap_s(t_pile *lst)
{
	swap_a(lst);
	swap_b(lst);
	ft_putstr("ss\n");
}

void	push_b(t_pile *lst)
{
	int	i;

	if (lst->max_a == 0)
		exit_free(lst, EXIT_FAILURE);
	i = lst->max_b - 1;
	while (i >= 0)
	{
		lst->b[i + 1] = lst->b[i];
		i--;
	}
	i = 0;
	lst->b[0] = lst->a[0];
	while (i < lst->max_a - 1)
	{
		lst->a[i] = lst->a[i + 1];
		i++;
	}
	lst->max_a--;
	lst->max_b++;
	ft_putstr("pb\n");
}

void	push_a(t_pile *lst)
{
	int	i;

	if (lst->max_b == 0)
		exit_free(lst, EXIT_FAILURE);
	i = lst->max_a - 1;
	while (i >= 0)
	{
		lst->a[i + 1] = lst->a[i];
		i--;
	}
	i = 0;
	lst->a[0] = lst->b[0];
	while (i < lst->max_b - 1)
	{
		lst->b[i] = lst->b[i + 1];
		i++;
	}
	lst->max_a++;
	lst->max_b--;
	ft_putstr("pa\n");
}
