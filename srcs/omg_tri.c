/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   omg_tri.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <tamigore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:59:21 by user42            #+#    #+#             */
/*   Updated: 2021/08/10 22:33:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			add_operation(t_pile *lst, int *op, int i)
{
	int			j;
	int			nb;

	j = 0;
	nb = 0;
	while (j < i)
	{
		if (check_pile(lst->a, lst->max_a))
			break ;
		if (op[j] == 0)
			nb = swap_a(lst);
		else if (op[j] == 1)
			nb = swap_b(lst);
		else if (op[j] == 2)
			nb = swap_s(lst);
		else if (op[j] == 3)
			nb = push_a(lst);
		else if (op[j] == 4)
			nb = push_b(lst);
		else if (op[j] == 5)
			nb = revers_a(lst);
		else if (op[j] == 6)
			nb = revers_b(lst);
		else if (op[j] == 7)
			nb = revers_r(lst);
		else if (op[j] == 8)
			nb = rrevers_a(lst);
		else if (op[j] == 9)
			nb = rrevers_b(lst);
		else if (op[j] == 10)
			nb = rrevers_r(lst);
		else
			exit_err(lst);
		lst->res[lst->index++] = nb;
		j++;
	}
}

void			get_best_op(t_pile * lst)
{
	int			i;
	int			nb;
	int			tmp;

	i = 0;
	while (i < lst->max_a)
	{
		if (i != a[i])
		{
			if (i > 3 && i < lst->max_a - 4)
				i++;
			else
				tmp = i < lst->max_a / 2 ? 1 : -1
		}
		res_tmp()
		i++;
	}
}

void			omg_tri(t_pile *lst)
{
	int			*op;
	int			i;

	op = (int *)malloc(sizeof(int) * lst->max_a);
	if (!op)
		exit_err(lst);
	while (!check_pile(lst->a, lst->max_a)) //&& !check_pile(lst->b, lst->max_b))
	{
		i = 0;
		while (lst->a[j] > i)
			j++;
		if ()
		add_operation(lst, op, i);
	}
	while (lst->max_b > 0)
		lst->res[lst->index++] = push_b(lst);
	free(op);
}

/*
void			omg_tri(t_pile *lst)
{
	int			*op;
	int			i;
	int			split;

	op = (int *)malloc(sizeof(int) * lst->max_a);
	if (!op)
		exit_err(lst, "Memory error in omg");
	split = lst->max_a / 2;
	while (!check_pile(lst->a, lst->max_a)) //&& !check_pile(lst->b, lst->max_b))
	{
		i = 0;
		// TRI A
		if (lst->a[0] > split)
		{
			if (lst->a[0] > lst->a[1] && lst->a[0] > lst->a[lst->max_a - 1])
			{
				if (lst->a[lst->max_a - 1] < lst->a[1])
				{
					if (lst->a[lst->max_a - 1] > split)
					{
						op[i++] = 8;
						op[i++] = 0;
						op[i++] = 5;
						op[i++] = 0;
						op[i++] = 5;
					}
					else
					{
						op[i++] = 8;
						op[i++] = 3;
					}
				}
				else
				{
					if (lst->a[1] > split)
						op[i++] = 5;
					else
					{
						op[i++] = 5;
						op[i++] = 3;
					}
				}
			}
			else if (lst->a[0] < lst->a[1] && lst->a[0] > lst->a[lst->max_a - 1])
			{
				if (lst->a[lst->max_a - 1] > split)
				{
					op[i++] = 0;
					op[i++] = 8;
					op[i++] = 0;
					op[i++] = 5;
					op[i++] = 0;
					op[i++] = 5;
				}
				else
				{
					op[i++] = 8;
					op[i++] = 3;
				}
			}
			else if (lst->a[0] > lst->a[1] && lst->a[0] < lst->a[lst->max_a - 1])
			{
				if (lst->a[1] > split)
				{
					op[i++] = 8;
					op[i++] = 0;
					op[i++] = 5;
					op[i++] = 5;
				}
				else
				{
					op[i++] = 0;
					op[i++] = 3;
				}
			}
			else
			{
				if (lst->a[1] < lst->a[lst->max_a - 1])
				{
					op[i++] = 0;
					op[i++] = 8;
					op[i++] = 0;
					op[i++] = 5;
					op[i++] = 5;
				}
				else
				{
					op[i++] = 0;
					op[i++] = 8;
					op[i++] = 0;
					op[i++] = 5;
					op[i++] = 5;
				}
			}
		}
		else
		{
			if (lst->a[0] > lst->a[1] && lst->a[0] > lst->a[lst->max_a - 1])
			{
				if (lst->a[1] < lst->a[lst->max_a - 1])
				{
					op[i++] = 8;
					op[i++] = 3;
				}
				else
				{
					op[i++] = 0;
					op[i++] = 3;
				}
			}
			else if (lst->a[0] < lst->a[1] && lst->a[0] > lst->a[lst->max_a - 1])
			{
				op[i++] = 8;
				op[i++] = 3;
			}
			else if (lst->a[0] > lst->a[1] && lst->a[0] < lst->a[lst->max_a - 1])
			{
				op[i++] = 0;
				op[i++] = 3;
			}
			else
				op[i++] = 3;
		}
		for (int j = 0; j < i; j++)
		{
			printf("op[%d] = %s\n", j, revers_act(op[j]));
		}
		// TRI B
	}
}
*/