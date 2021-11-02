/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:14:32 by tamigore          #+#    #+#             */
/*   Updated: 2021/10/24 17:14:34 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	track_sup(t_pile *lst, int *min)
{
	int	i;

	i = 0;
	while (i < lst->max_b)
	{
		if (lst->b[i] == *min)
			lst->pos.x = i + lst->max_a;
		else if (lst->b[i] == *min + 1)
			lst->pos.y = i + lst->max_a;
		i++;
	}
}

static void	track_add(t_pile *lst)
{
	if (lst->pos.x < lst->max_a)
	{
		if (lst->pos.y < lst->pos.x)
			lst->pos.check = 1;
	}
	else
	{
		if (lst->pos.x - lst->max_a < lst->max_b / 2)
		{
			if (lst->pos.y < lst->pos.x && lst->pos.y >= lst->max_a)
			{
				lst->pos.check = 1;
				lst->pos.y -= lst->max_a;
			}
		}
		else
		{
			if (lst->pos.y > lst->pos.x)
			{
				lst->pos.check = 1;
				lst->pos.y = (lst->max_b - 1) - (lst->pos.y - lst->max_a);
			}
		}
	}
}

void	track(t_pile *lst, int *min, int max)
{
	int	i;

	i = 0;
	lst->pos.check = 0;
	while (i < lst->max_a)
	{
		if (lst->a[i] == *min)
		{
			if (i == lst->max_a - 1)
			{
				(*min)++;
				track(lst, min, max);
			}
			lst->pos.x = i;
		}
		if (lst->a[i] == *min + 1)
			lst->pos.y = i;
		i++;
	}
	track_sup(lst, min);
	track_add(lst);
	if (*min == max - 1 || max)
		lst->pos.check = 0;
}
