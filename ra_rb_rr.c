/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:05:23 by mnathali          #+#    #+#             */
/*   Updated: 2022/02/13 15:05:25 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a)
{
	t_list	*change;

	if (*stack_a && (*stack_a)->next)
	{
		change = *stack_a;
		*stack_a = (*stack_a)->next;
		change->next = 0;
		ft_lstadd_back(stack_a, change);
		ft_putstr_fd("ra\n", 1);
	}
	return ;
}

void	rb(t_list **stack_b)
{
	t_list	*change;

	if (*stack_b && (*stack_b)->next)
	{
		change = *stack_b;
		*stack_b = (*stack_b)->next;
		change->next = 0;
		ft_lstadd_back(stack_b, change);
		ft_putstr_fd("rb\n", 1);
	}
	return ;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*change;

	if (*stack_a && (*stack_a)->next && *stack_b && (*stack_b)->next)
	{
		change = *stack_a;
		*stack_a = (*stack_a)->next;
		change->next = 0;
		ft_lstadd_back(stack_a, change);
		change = *stack_b;
		*stack_b = (*stack_b)->next;
		change->next = 0;
		ft_lstadd_back(stack_b, change);
		ft_putstr_fd("rr\n", 1);
	}
	return ;
}
