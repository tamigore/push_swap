/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <tamigore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:55:56 by user42            #+#    #+#             */
/*   Updated: 2021/11/02 17:05:02 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_err(t_pile *lst)
{
	if (lst)
	{
		if (lst->a)
			free(lst->a);
		if (lst->b)
			free(lst->b);
		if (lst->res)
			free(lst->res);
		free(lst);
	}
	ft_putstr("Error\n");
	exit(EXIT_FAILURE);
}

void	exit_valid(t_pile *lst)
{
	if (lst)
	{
		if (lst->a)
			free(lst->a);
		if (lst->b)
			free(lst->b);
		if (lst->res)
			free(lst->res);
		free(lst);
	}
	exit(EXIT_SUCCESS);
}

char	*revers_act(int nb)
{
	if (nb == 0)
		return ("sa");
	else if (nb == 1)
		return ("sb");
	else if (nb == 2)
		return ("ss");
	else if (nb == 3)
		return ("pa");
	else if (nb == 4)
		return ("pb");
	else if (nb == 5)
		return ("ra");
	else if (nb == 6)
		return ("rb");
	else if (nb == 7)
		return ("rr");
	else if (nb == 8)
		return ("rra");
	else if (nb == 9)
		return ("rrb");
	else if (nb == 10)
		return ("rrr");
	exit_err(NULL);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_pile	*lst;

	if (ac < 2)
		exit(0);
	lst = init_pile(ac, av);
	solve(lst);
	exit_valid(lst);
	return (0);
}
