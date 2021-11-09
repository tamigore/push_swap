/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <tamigore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:55:56 by user42            #+#    #+#             */
/*   Updated: 2021/11/09 13:53:26 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_free(t_pile *lst, int ret)
{
	if (lst)
	{
		if (lst->a)
			free(lst->a);
		if (lst->b)
			free(lst->b);
		free(lst);
	}
	if (ret == EXIT_FAILURE)
		ft_putstr("Error\n");
	exit(ret);
}

int	main(int ac, char **av)
{
	t_pile	*lst;

	if (ac < 2)
		exit(0);
	lst = init_pile(ac, av);
	solve(lst);
	exit_free(lst, EXIT_SUCCESS);
	return (0);
}
