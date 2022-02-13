/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recoursion_isolate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:06:24 by mnathali          #+#    #+#             */
/*   Updated: 2022/02/13 15:06:26 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	positive_pass(t_list **stack_d, t_list **stack, int n, int med)
{
	while (n > 0)
	{
		if (*(int *)(*stack_d)->content <= med)
			pb(stack_d, stack);
		else
		{
			ra(stack_d);
			if (ft_lstsize(*stack_d) == 1 && n - 1 == 0)
				ft_putstr_fd("ra\n", 1);
		}
		n--;
	}
	rra(stack_d);
	return (n);
}

int	negative_pass(t_list **stack_d, t_list **stack, int n, int med)
{
	while (n < 0)
	{
		if (*(int *)(*stack_d)->content <= med)
		{
			if (ft_lstsize(*stack_d) == 1)
				ft_putstr_fd("rra\n", 1);
			pb(stack_d, stack);
			if (n + 1 != 0)
				rra(stack_d);
		}
		else
		{
			rra(stack_d);
			if (ft_lstsize(*stack_d) > 1 && n + 1 == 0)
				ra(stack_d);
			else if (ft_lstsize(*stack_d) == 1 && n + 1 == 0)
				ft_putstr_fd("rra\n", 1);
		}
		n++;
	}
	return (n);
}

void	recoursion_isolate(t_list **stack_d, t_list **stack_a, short sign)
{
	t_list	*stack;
	int		med;
	int		n;

	stack = 0;
	n = sign * ft_lstsize(*stack_d);
	med = mediana(*stack_d);
	if (n > 0)
		n = positive_pass(stack_d, &stack, n, med);
	if (n < 0)
		n = negative_pass(stack_d, &stack, n, med);
	if (*stack_d)
		recoursion_isolate(stack_d, stack_a, -1 * sign);
	if (ft_lstsize(stack) > 20)
	{
		while (stack)
			pa(stack_d, &stack);
		recoursion_isolate(stack_d, stack_a, 1);
	}
	ft_pa(stack_a, &stack);
	return ;
}
