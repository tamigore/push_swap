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

static void	check_number(char *str, t_pile *lst)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+')
			exit_err(lst);
		i++;
	}
}

static long long int	push_swap_atoi(t_pile *lst, char *str)
{
	int						i;
	int						neg;
	unsigned long long int	nb;

	check_number(str, lst);
	i = 0;
	neg = 1;
	nb = 0;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + str[i++] - '0';
	if ((long long)(nb * neg) > 2147483647 ||
		(long long)(nb * neg) < -2147483648)
		exit_err(lst);
	return (nb * neg);
}

static void	init_a(t_pile *lst, int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac - 1)
	{
		lst->a[i] = push_swap_atoi(lst, av[i + 1]);
		i++;
	}
	i = 0;
	while (i < ac - 1)
	{
		j = 0;
		while (j < ac - 1)
		{
			if ((lst->a[i] == lst->a[j]) && i != j)
				exit_err(lst);
			j++;
		}
		i++;
	}
}

static void	set(t_pile *lst, int ac)
{
	lst->valid = 0;
	lst->max_a = ac - 1;
	lst->max_b = 0;
	lst->index = 0;
	lst->b = NULL;
	lst->res = NULL;
	lst->a = (int *)malloc(sizeof(int) * lst->max_a);
	if (!lst->a)
	{
		lst->a = NULL;
		exit_err(lst);
	}
}

t_pile	*init_pile(int ac, char **av)
{
	t_pile	*lst;

	lst = (t_pile *)malloc(sizeof(t_pile));
	if (!lst)
		exit(EXIT_FAILURE);
	set(lst, ac);
	init_a(lst, ac, av);
	lst->b = (int *)malloc(sizeof(int) * lst->max_a);
	if (!lst->b)
	{
		lst->b = NULL;
		exit_err(lst);
	}
	lst->res = (int *)malloc(sizeof(int) * (BUFFER_SIZE));
	if (!lst->res)
	{
		lst->res = NULL;
		exit_err(lst);
	}
	ft_bzero(lst->b, lst->max_a);
	ft_bzero(lst->res, BUFFER_SIZE);
	return (lst);
}
