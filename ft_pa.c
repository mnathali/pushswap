/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:50:50 by mnathali          #+#    #+#             */
/*   Updated: 2022/02/13 14:50:52 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_b(t_list **stack_b, int med)
{
	if (med > *(int *)(*stack_b)->content)
	{
		if (ft_lstsize(*stack_b) / 2 - nearer(*stack_b, med) > 0)
		{
			while (*(int *)(*stack_b)->content < med)
				rb(stack_b);
		}
		else
		{
			while (*(int *)(*stack_b)->content < med)
				rrb(stack_b);
		}
	}
}

void	ft_pa_pa(t_list **stack_a, t_list **stack_b)
{
	int	med;

	while (*stack_b)
	{
		med = mediana(*stack_b);
		complex_sort_b(stack_b, &evaluate, &ft_criteria);
		while (*stack_b && max_value(*stack_b) >= med)
		{
			rotate_b(stack_b, med);
			if (*(int *)(*stack_a)->content > *(int *)(*stack_b)->content
			&& take_back(*stack_a) < *(int *)(*stack_b)->content)
				pa(stack_a, stack_b);
			else if (*(int *)(*stack_b)->content < min_value(*stack_a)
			&& *(int *)(*stack_a)->content == min_value(*stack_a))
				pa(stack_a, stack_b);
			else if (evaluate(*stack_b, "s") < ft_criteria(*stack_b))
				sb(stack_b);
			else if (ft_lstsize(*stack_a) / 2 - count_rs_rrs(*stack_a,
					*(int *)(*stack_b)->content, min_value(*stack_a),
				max_value(*stack_a)) > 0)
				ra(stack_a);
			else
				rra(stack_a);
		}
	}
}

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	while (*stack_b)
	{
		if (*(int *)(*stack_a)->content > *(int *)(*stack_b)->content
		&& take_back(*stack_a) < *(int *)(*stack_b)->content)
			pa(stack_a, stack_b);
		else if (*(int *)(*stack_b)->content < min_value(*stack_a)
		&& *(int *)(*stack_a)->content == min_value(*stack_a))
			pa(stack_a, stack_b);
		else if (evaluate(*stack_b, "s") < ft_criteria(*stack_b))
			sb(stack_b);
		else if (ft_lstsize(*stack_a) / 2 - count_rs_rrs(*stack_a,
				*(int *)(*stack_b)->content, min_value(*stack_a),
			max_value(*stack_a)) > 0)
			ra(stack_a);
		else
			rra(stack_a);
	}
	return ;
}
