#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->count = 0;
	stack->begin = NULL;
	stack->end = NULL;
}

void	parser(int ac, char **av, t_stack *a)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		t_slist *tmp = (t_slist*)malloc(sizeof(t_slist));
		init_slist(tmp, NULL, NULL, ft_atoi(av[i]));
		stack_push_back(a, tmp);
		i++;
	}
}

void	check_stack(t_stack *a, t_stack *b)
{
	b = NULL;
	for (int i = 0; i < 6; i++) {
		rra(a);
		printf("%p %d\n", a->begin, a->begin->num);
	}
}

int		main(int ac, char **av)
{
	t_stack	a;
	t_stack b;

	init_stack(&a);
	init_stack(&b);
	parser(ac, av, &a);
	check_stack(&a, &b);
}
