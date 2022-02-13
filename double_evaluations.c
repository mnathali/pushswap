/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_evaluations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:44:39 by mnathali          #+#    #+#             */
/*   Updated: 2022/02/13 14:44:40 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	evaluate_r_s(t_list *stack)
{
	int		n;
	t_list	*lst;

	lst = stack;
	if (!lst || !lst->next || !(lst->next->next))
		return (0);
	if (!(lst->next->next->next))
		return ((-1) * ft_criteria(stack));
	n = ft_criteria(lst->next->next->next);
	if (*(int *)lst->next->next->content < *(int *)lst->next->content)
		n++;
	else
		n--;
	if (((lst->next)->next)->next
		&& *(int *)lst->next->next->next->content > *(int *)lst->next->content)
		n++;
	else
		n--;
	while (lst->next != 0)
		lst = lst->next;
	if (*(int *)lst->content < *(int *)stack->content)
		n++;
	else
		n--;
	return (n);
}

int	evaluate_s_r(t_list *stack)
{
	int		n;
	t_list	*lst;

	lst = stack;
	if (!lst || !lst->next || !(lst->next)->next)
		return (0);
	n = ft_criteria((lst->next)->next);
	if (*(int *)lst->content < *(int *)((lst->next)->next)->content)
		n++;
	else
		n--;
	while (lst->next != 0)
		lst = lst->next;
	if (*(int *)lst->content <= *(int *)(stack->next)->content)
		n++;
	else
		n--;
	return (n);
}

int	evaluate_rr_s(t_list *stack)
{
	int		n;
	t_list	*lst;

	if (!stack || !stack->next || !stack->next->next)
		return (0);
	n = 0;
	lst = (stack)->next;
	while ((lst->next)->next != 0)
	{
		if (*(int *)lst->next->content > *(int *)lst->content)
			n++;
		else
			n--;
		lst = lst->next;
	}
	if (*(int *)lst->next->content < *(int *)stack->next->content)
		n++;
	else
		n--;
	if (*(int *)stack->content < *(int *)lst->next->content)
		n++;
	else
		n--;
	return (n);
}

int	evaluate_part_s_rr(t_list *stack, t_list *lst, int n)
{
	if (lst->next && *(int *)lst->next->content < *(int *)stack->next->content)
		n++;
	else if (lst->next)
		n--;
	if (*(int *)stack->content < *(int *)stack->next->next->content)
		n++;
	else
		n--;
	if (*(int *)(stack->next)->content < *(int *)stack->content)
		n++;
	else
		n--;
	return (n);
}

int	evaluate_s_rr(t_list *stack)
{
	int		n;
	t_list	*lst;

	if (!stack || !stack->next || !(stack->next)->next)
		return (0);
	n = 0;
	lst = (stack->next)->next;
	while (lst->next && (lst->next)->next != 0)
	{
		if (*(int *)(lst->next)->content >= *(int *)lst->content)
			n++;
		else
			n--;
		lst = lst->next;
	}
	n = evaluate_part_s_rr(stack, lst, n);
	return (n);
}
