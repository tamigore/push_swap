/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <tamigore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:55:56 by user42            #+#    #+#             */
/*   Updated: 2021/08/10 22:27:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			exit_err(t_pile *lst)
{
	if (lst->a)
		free(lst->a);
	if (lst->b)
		free(lst->b);
	if (lst->res)
		free(lst->res);
	if (lst)
		free(lst);
	ft_putstr("Error\n");
	exit(EXIT_FAILURE);
}

void			print_pile(t_pile *lst)
{
	int			i;

	i = 0;
	if (!lst)
		exit_err(NULL);
	printf("///////////////////PRINT_PILE///////////////////\n");
	printf("Valid : %d\nMax_a : %d\nMax_b : %d\nPile A:\n", lst->valid, lst->max_a, lst->max_b);
	while (i < lst->max_a)
	{
		printf("pile a[%d] : %d\n", i, lst->a[i]);
		i++;
	}
	i = 0;
	printf("Pile B:\n");
	while (i < lst->max_b)
	{
		printf("pile b[%d] : %d\n", i, lst->b[i]);
		i++;
	}
	i = 0;
	printf("Resultat :\n");
	while (i < lst->index)
	{
		printf("res[%d] : %s\n", i, revers_act(lst->res[i]));
		i++;
	}
	printf("////////////////////////////////////////////////\n");
}

char			*revers_act(int nb)
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
	printf("nb = %d\n", nb);
	exit_err(NULL);
	return (NULL);
}

int				main(int ac, char **av)
{
	t_pile		*lst;
	int			i;

	if (ac < 2)
		exit(0);
	lst = init_pile(ac, av);
//	print_pile(lst);
	solve(lst);
//	print_pile(lst);
	i = 0;
	while (i < lst->index)
	{
		ft_putstr(revers_act(lst->res[i++]));
		ft_putstr("\n");
	}
	return (0);
}
