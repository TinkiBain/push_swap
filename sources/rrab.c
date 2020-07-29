#include "push_swap.h"

void		rra(t_stack *a)
{
	stack_push_front(a, stack_erase_end(a));
	ft_putstr("rra\n");
}

void		rrb(t_stack *b)
{
	stack_push_back(b, stack_erase_begin(b));
	ft_putstr("rrb\n");
}

void		rrr(t_stack *a, t_stack *b)
{
	stack_push_back(a, stack_erase_begin(a));
	stack_push_back(b, stack_erase_begin(b));
	ft_putstr("rrr\n");
}
