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

#ifndef __PUSH_SWAP_H__
# define __PUSH_SWAP_H__

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef	enum		s_act
{
	sa,// 0
	sb,// 1
	ss,// 2
	pa,// 3
	pb,// 4
	ra,// 5
	rb,// 6
	rr,// 7
	rra,// 8
	rrb,// 9
	rrr// 10
}					t_act;

typedef struct		s_pos
{
	int		check;
	int		x;
	int		y;
}					t_pos;

typedef	struct		s_pile
{
	int				valid;
	int				*a;
	int				*b;
	int				*res;
	struct s_pos	pos;
	int				index;
	int				max_a;
	int				max_b;
}					t_pile;

/*
** swap.c
*/

int					swap_a(t_pile *lst);
int					swap_b(t_pile *lst);
int					swap_s(t_pile *lst);
int					push_a(t_pile *lst);
int					push_b(t_pile *lst);

/*
** revers.c
*/

int					revers_a(t_pile *lst);
int					revers_b(t_pile *lst);
int					revers_r(t_pile *lst);
int					rrevers_a(t_pile *lst);
int					rrevers_b(t_pile *lst);
int					rrevers_r(t_pile *lst);

/*
** algo.c
*/

void				get_unified_pile(t_pile *lst);
void				solve(t_pile *lst);
void				put_res(t_pile *lst, int (*fun)(t_pile *lst));

/*
** check.c
*/

int					check_all(t_pile *lst);
int					check_pile(int *p, int max);
int					check_revers_pile(int *p, int max);

/*
** tri_min.c
*/

void				sort_min(t_pile *lst);

/*
** omg_tri.c
*/

void				add_operation(t_pile *lst, int *op, int i);
void				omg_tri(t_pile *lst);

/*
** main.c
*/

void				exit_err(t_pile *lst);
char				*revers_act(int nb);
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

void				radixsort(t_pile *lst);

#endif