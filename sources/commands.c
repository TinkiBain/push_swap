#include "push_swap.h"

#include <stdio.h>

void	swap_slist_value(t_slist* left, t_slist* right)
{
	t_slist tmp;

	init_slist(&tmp, left->next, left->prev, left->num);
	init_slist(left, right->next, right->prev, right->num);
	init_slist(right, tmp.next, tmp.prev, tmp.num);
}

void	init_slist(t_slist *list, t_slist *next, t_slist *prev, int num)
{
	list->next = next;
	list->prev = prev;
	list->num = num;
}

t_slist		*stack_erase_begin(t_stack *stack)
{
	t_slist	*tmp;
	
	tmp = stack->begin;
	stack->begin = tmp->next;
	if (stack->begin)
		stack->begin->prev = NULL;
	tmp->next = NULL;
	stack->count--;
	if (!stack->count)
		stack->end = NULL;
	return (tmp);
}

t_slist		*stack_erase_end(t_stack *stack)
{
	t_slist	*tmp;

	tmp = stack->end;
	stack->end = tmp->prev;
	if (stack->end)
		stack->end->next = NULL;
	tmp->prev = NULL;
	stack->count--;
	if (!stack->count)
		stack->begin = NULL;
	return (tmp);

}

void	stack_push_back(t_stack *stack, t_slist *list)
{
	if (stack->end) {
		stack->end->next = list;
		list->prev = stack->end;
	} else {
		stack->begin = list;
	}
	stack->end = list;
	stack->count++;
}

void	stack_push_front(t_stack *stack, t_slist *list)
{
	if (stack->begin) {
		stack->begin->prev = list;
		list->next = stack->begin;
	} else {
		stack->end = list;
	}
	stack->begin = list;
	stack->count++;
}
