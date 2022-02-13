/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recoursion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:06:10 by mnathali          #+#    #+#             */
/*   Updated: 2022/02/13 15:06:12 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_push(t_list **stack_a, t_list **stack_b)
{
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	optimizations(t_list **stack_a, t_list **stack, t_list **stack_d,
	void (*f)(t_list **, t_list **))
{
	while (ft_lstsize(*stack) > 40)
	{
		f(stack_d, stack);
		recoursion_isolate(stack_d, stack_a, 1);
	}
}

void	first_part(t_list **stack_a, t_list **stack, int med, int size)
{
	while (min_value(*stack_a) < med
		&& ft_criteria(*stack_a) < ft_lstsize(*stack_a) - 1)
	{
		if (*(int *)(*stack_a)->content < med)
			pb(stack_a, stack);
		else if (ft_lstsize(*stack_a) / 2
			- path_to_number(*stack_a, '<', med) > 0)
			ra(stack_a);
		else
			rra(stack_a);
	}
	recoursion(stack_a, size);
	return ;
}

void	recoursion(t_list **stack_a, int size)
{
	t_list	*stack;
	t_list	*stack_d;
	int		med;

	stack = 0;
	stack_d = 0;
	complex_sort(stack_a, &evaluate, &ft_criteria);
	med = mediana(*stack_a);
	if (ft_criteria(*stack_a) < ft_lstsize(*stack_a) - 1)
		first_part(stack_a, &stack, med, size);
	if (ft_lstsize(stack) > size / 3 && ft_lstsize(stack) > 30)
	{
		bigger_half(&stack_d, &stack);
		recoursion_isolate(&stack_d, stack_a, 1);
		optimizations(stack_a, &stack, &stack_d, &bigger_half);
		ft_pa_pa(stack_a, &stack);
	}
	optimizations(stack_a, &stack, &stack_d, &simple_push);
	ft_pa(stack_a, &stack);
	return ;
}
