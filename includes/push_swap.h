/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <tamigore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:08:52 by user42            #+#    #+#             */
/*   Updated: 2021/08/10 22:11:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

typedef struct s_pos
{
	int		check;
	int		x;
	int		y;
}	t_pos;

typedef struct s_pile
{
	int				valid;
	int				*a;
	int				*b;
	struct s_pos	pos;
	int				max_a;
	int				max_b;
}	t_pile;

/*
** swap.c
*/

void				swap_a(t_pile *lst);
void				swap_b(t_pile *lst);
void				swap_s(t_pile *lst);
void				push_a(t_pile *lst);
void				push_b(t_pile *lst);

/*
** revers.c
*/

void				revers_a(t_pile *lst);
void				revers_b(t_pile *lst);
void				revers_r(t_pile *lst);

/*
** rrevers.c
*/

void				rrevers_a(t_pile *lst);
void				rrevers_b(t_pile *lst);
void				rrevers_r(t_pile *lst);

/*
** algo.c
*/

void				get_unified_pile(t_pile *lst);
void				solve(t_pile *lst);

/*
** check.c
*/

int					check_all(t_pile *lst);

/*
** main.c
*/

void				exit_free(t_pile *lst, int ret);
void				print_pile(t_pile *lst);

/*
** init.c
*/

t_pile				*init_pile(int ac, char **av);

/*
** sort.c
*/

void				sort(t_pile *lst);

/*
** track.c
*/

void				track(t_pile *lst, int *min, int max);

/*
** radixsort.c
*/

void				radix_sort(t_pile *lst);

#endif