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

typedef	enum	s_bool
{
	false,
	true
}				t_bool;

typedef	enum	s_act
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
}				t_act;

typedef	struct	s_pile
{
	t_bool		valid;
	int			*a;
	int			*b;
	int			*res;
	int			index;
	int			max_a;
	int			max_b;
}				t_pile;

int				swap_a(t_pile *lst);
int				swap_b(t_pile *lst);
int				swap_s(t_pile *lst);
int				push_a(t_pile *lst);
int				push_b(t_pile *lst);

int				revers_a(t_pile *lst);
int				revers_b(t_pile *lst);
int				revers_r(t_pile *lst);
int				rrevers_a(t_pile *lst);
int				rrevers_b(t_pile *lst);
int				rrevers_r(t_pile *lst);

void			get_unified_pile(t_pile *lst);
void			get_best_res(t_pile *lst);
int				check_all(t_pile *lst);
int				check_pile(int *p, int max);

int				get_placement(t_pile *lst, int nb);
void			tri_min(t_pile *lst);

void			omg_tri(t_pile *lst);

void			exit_err(void *ptr, char *str);
char			*revers_act(int nb);
void			print_pile(t_pile *lst);
#endif
