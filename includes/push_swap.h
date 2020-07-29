#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

#include "libft.h"

typedef struct	s_slist {
	struct s_slist	*next;
	struct s_slist	*prev;
	int				num;
}				t_slist;

typedef struct	s_stack {
	int		count;
	t_slist	*begin;
	t_slist	*end;
}				t_stack;

t_slist		*stack_erase_begin(t_stack *stack);
t_slist		*stack_erase_end(t_stack *stack);
void		stack_push_back(t_stack *stack, t_slist *list);
void		stack_push_front(t_stack *stack, t_slist *list);
void		init_slist(t_slist *list, t_slist *next, t_slist *prev, int num);
void		swap_slist_value(t_slist *left, t_slist *right);
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *b, t_stack *a);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);

#endif
