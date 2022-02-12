#include "push_swap.h"

void	sa(t_list **stack_a)
{
	t_list	*change;

	if (*stack_a && (*stack_a)->next)
	{
		change = (*stack_a)->next;
		(*stack_a)->next = change->next;
		change->next = *stack_a;
		*stack_a = change;
		ft_putstr_fd("sa\n", 1);
	}
	return ;
}

void	sb(t_list **stack_b)
{
	t_list	*change;

	if (*stack_b && (*stack_b)->next)
	{
		change = (*stack_b)->next;
		(*stack_b)->next = change->next;
		change->next = *stack_b;
		*stack_b = change;
		ft_putstr_fd("sb\n", 1);
	}
	return ;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	t_list	*change;

	if (*stack_a && (*stack_a)->next && *stack_b && (*stack_b)->next)
	{
		change = (*stack_a)->next;
		(*stack_a)->next = change->next;
		change->next = *stack_a;
		*stack_a = change;
		change = (*stack_b)->next;
		(*stack_b)->next = change->next;
		change->next = *stack_b;
		*stack_b = change;
		ft_putstr_fd("ss\n", 1);
	}
	return ;
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*change;

	if (*stack_a)
	{
		change = *stack_a;
		*stack_a = (*stack_a)->next;
		change->next = *stack_b;
		*stack_b = change;
		ft_putstr_fd("pb\n", 1);
	}
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*change;

	if (*stack_b)
	{
		change = *stack_b;
		*stack_b = (*stack_b)->next;
		change->next = *stack_a;
		*stack_a = change;
		ft_putstr_fd("pa\n", 1);
	}
}