#include "push_swap.h"

static void		sab(t_stack *stack) {
	t_slist		*tmp;

	tmp = stack->begin->next;
	if (tmp->next)
		tmp->next->prev = stack->begin;
	stack->begin->prev = tmp;
	stack->begin->next = tmp->next;
	tmp->prev = NULL;
	tmp->next = stack->begin;
	stack->begin = tmp;
	if (stack->begin == stack->end)
		stack->end = stack->begin->next;
}

void			sa(t_stack *a)
{
	sab(a);
	ft_putstr("sa\n");
}

void			sb(t_stack *b)
{
	sab(b);
	ft_putstr("sb\n");
}

void			ss(t_stack *a, t_stack *b)
{
	sab(a);
	sab(b);
	ft_putstr("ss\n");
}
