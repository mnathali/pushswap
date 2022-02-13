/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_criteria.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:49:32 by mnathali          #+#    #+#             */
/*   Updated: 2022/02/13 14:49:37 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_criteria(t_list *stack)
{
	int		n;
	t_list	*lst;

	lst = stack;
	n = 0;
	while (lst && lst->next != 0)
	{
		if (*(int *)(lst->next)->content >= *(int *)lst->content)
			n++;
		else
			n--;
		lst = lst->next;
	}
	return (n);
}
