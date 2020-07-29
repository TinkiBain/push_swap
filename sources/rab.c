#include "push_swap.h"

void		ra(t_stack *a)
{
	stack_push_back(a, stack_erase_begin(a));
	ft_putstr("ra\n");
}

void		rb(t_stack *b)
{
	stack_push_back(b, stack_erase_begin(b));
	ft_putstr("rb\n");
}

void		rr(t_stack *a, t_stack *b)
{
	stack_push_back(a, stack_erase_begin(a));
	stack_push_back(b, stack_erase_begin(b));
	ft_putstr("rr\n");
}
