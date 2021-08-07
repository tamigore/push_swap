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
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
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

void			exit_err(void *ptr, char *str);

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

#endif
