#include "push_swap.h"

void			pa(t_stack *a, t_stack *b)
{
	stack_push_front(a, stack_erase_begin(b));
	ft_putstr("pa\n");
}

void			pb(t_stack *b, t_stack *a) {
	stack_push_front(b, stack_erase_begin(a));
	ft_putstr("pb\n");
}		
