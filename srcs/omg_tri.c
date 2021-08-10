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
