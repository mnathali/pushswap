/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_calculations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:37:28 by mnathali          #+#    #+#             */
/*   Updated: 2022/02/13 14:37:40 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	take_back(t_list *stack)
{
	while (stack->next)
		stack = stack->next;
	return (*(int *)stack->content);
}

void	bigger_half(t_list **stack_a, t_list **stack_b)
{
	int	med;
	int	sz;

	med = mediana(*stack_b);
	sz = ft_lstsize(*stack_b);
	while (sz)
	{
		if (*(int *)(*stack_b)->content >= med)
			pa(stack_a, stack_b);
		else
			rb(stack_b);
		sz--;
	}
}

int	where_min_max(t_list *stack_a, int min_max)
{
	int	n;

	n = 0;
	while (*(int *)stack_a->content != min_max)
	{
		n++;
		stack_a = stack_a->next;
	}
	return (n);
}

int	count_rs_rrs(t_list *stack_a, int content, int min, int max)
{
	int	n;

	n = 0;
	if (content > max)
		return (where_min_max(stack_a, max));
	if (content < min)
		return (where_min_max(stack_a, min));
	while (content < *(int *)stack_a->content)
	{
		n++;
		stack_a = stack_a->next;
	}
	while (stack_a && content > *(int *)stack_a->content)
	{
		n++;
		stack_a = stack_a->next;
	}
	return (n);
}
