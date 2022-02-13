/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:05:29 by mnathali          #+#    #+#             */
/*   Updated: 2022/02/13 15:05:30 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack_a)
{
	t_list	*change;

	change = *stack_a;
	if (*stack_a && (*stack_a)->next)
	{
		while ((change->next)->next != 0)
			change = change->next;
		ft_lstadd_front(stack_a, change->next);
		change->next = 0;
		ft_putstr_fd("rra\n", 1);
	}
	return ;
}

void	rrb(t_list **stack_b)
{
	t_list	*change;

	change = *stack_b;
	if (*stack_b && (*stack_b)->next)
	{
		while ((change->next)->next != 0)
			change = change->next;
		ft_lstadd_front(stack_b, change->next);
		change->next = 0;
		ft_putstr_fd("rrb\n", 1);
	}
	return ;
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*change;

	change = *stack_a;
	if (*stack_a && (*stack_a)->next && *stack_b && (*stack_b)->next)
	{
		while ((change->next)->next != 0)
			change = change->next;
		ft_lstadd_front(stack_a, change->next);
		change->next = 0;
		change = *stack_b;
		while ((change->next)->next != 0)
			change = change->next;
		ft_lstadd_front(stack_b, change->next);
		change->next = 0;
		ft_putstr_fd("rrr\n", 1);
	}
	return ;
}
