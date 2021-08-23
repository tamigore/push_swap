/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <tamigore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:15:19 by user42            #+#    #+#             */
/*   Updated: 2021/08/13 21:44:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long int		push_swap_atoi(t_pile *lst, int *a, char *str)
{
	int						i;
	int						neg;
	int						test;
	unsigned long long int	nb;

	i = 0;
	neg = 1;
	nb = 0;
	while ((str[i] <= '\r' && str[i] >= '\r') || str[i] == ' ')
		i++;
	test = i;
	while (str[test])
	{
		if (str[test] < '0' || str[test] > '9')
		{
			free(a);
			exit_err(lst);
		}
		test++;
	}
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + str[i++] - '0';
	if ((long long)(nb * neg) > 2147483647 || (long long)(nb * neg) < -2147483648)
		exit_err(lst);
	return (nb * neg);
}

int				*init_a(t_pile *lst, int ac, char **av)
{
	int			*a;
	int			i;
	int			j;

	a = (int *)malloc(sizeof(int) * lst->max_a);
	if (!a)
		exit_err(lst);
	i = 0;
	while (i < ac - 1)
	{
		a[i] = push_swap_atoi(lst, a, av[i + 1]);
		i++;
	}
	i = 0;
	while (i < ac - 1)
	{
		j = 0;
		while (j < ac - 1)
		{
			if ((a[i] == a[j]) && i != j)
			{
				free(a);
				exit_err(lst);
			}
			j++;
		}
		i++;
	}
	return (a);
}

t_pile			*init_pile(int ac, char **av)
{
	t_pile		*lst;

	lst = (t_pile *)malloc(sizeof(t_pile));
	if (!lst)
		exit(EXIT_FAILURE);
	lst->valid = 0;
	lst->max_a = ac - 1;
	lst->max_b = 0;
	lst->index = 0;
	lst->a = init_a(lst, ac, av);
	lst->b = (int *)malloc(sizeof(int) * lst->max_a);
	if (!lst->b)
	{
		free(lst->a);
		exit_err(lst);
	}
	lst->res = (int *)malloc(sizeof(int) * lst->max_a * 4);
	if (!lst->res)
	{
		free(lst->b);
		free(lst->a);
		exit_err(lst);
	}
	ft_bzero(lst->op, 10);
	ft_bzero(lst->b, lst->max_a);
	ft_bzero(lst->res, lst->max_a * 4);
	return (lst);
}