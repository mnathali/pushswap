/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:39:55 by mnathali          #+#    #+#             */
/*   Updated: 2022/02/13 14:39:58 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_value(t_list *stack)
{
	int	min;

	min = *(int *)stack->content;
	while (stack)
	{
		if (*(int *)stack->content < min)
			min = *(int *)stack->content;
		stack = stack->next;
	}
	return (min);
}

int	max_value(t_list *stack)
{
	int	max;

	max = *(int *)stack->content;
	while (stack)
	{
		if (*(int *)stack->content > max)
			max = *(int *)stack->content;
		stack = stack->next;
	}
	return (max);
}

int	mediana(t_list *stack)
{
	int		mediana;
	t_list	*lst_1;
	t_list	*lst_2;
	int		n;

	lst_2 = stack;
	while (lst_2)
	{
		lst_1 = stack;
		n = 0;
		mediana = *(int *)lst_2->content;
		while (lst_1)
		{
			if (mediana > *(int *)lst_1->content)
				n++;
			else if (mediana != *(int *)lst_1->content)
				n--;
			lst_1 = lst_1->next;
		}
		lst_2 = lst_2->next;
		if (n >= -1 && n <= 1)
			break ;
	}
	return (mediana);
}

int	path_to_number(t_list *stack, char index, int med)
{
	int	n;

	if (!stack)
		return (0);
	n = 0;
	while (index == '>' && *(int *)stack->content <= med)
	{
		stack = stack->next;
		n++;
	}
	while (index == '<' && *(int *)stack->content >= med)
	{
		stack = stack->next;
		n++;
	}
	return (n);
}

int	nearer(t_list *stack, int med)
{
	int	n;

	n = 0;
	while (*(int *)stack->content < med)
	{
		n++;
		stack = stack->next;
	}
	return (n);
}
