/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:41:38 by mnathali          #+#    #+#             */
/*   Updated: 2022/02/13 14:41:40 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void	ft_lstputnbr(t_list *lst)
{
	while (lst != 0)
	{
		ft_putnbr_fd(*(int *)lst->content, 1);
		write(1, " ", 1);
		lst = lst->next;
	}
	write(1, "\n", 1);
}

short	make_action(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!ft_strncmp(str, "sa", 2) && ft_strlen(str) == 3)
		sa(stack_a);
	else if (!ft_strncmp(str, "sb", 2) && ft_strlen(str) == 3)
		sb(stack_b);
	else if (!ft_strncmp(str, "rra", 3) && ft_strlen(str) == 4)
		rra(stack_a);
	else if (!ft_strncmp(str, "rrb", 3) && ft_strlen(str) == 4)
		rrb(stack_b);
	else if (!ft_strncmp(str, "ra", 2) && ft_strlen(str) == 3)
		ra(stack_a);
	else if (!ft_strncmp(str, "rb", 2) && ft_strlen(str) == 3)
		rb(stack_b);
	else if (!ft_strncmp(str, "pa", 2) && ft_strlen(str) == 3)
		pa(stack_a, stack_b);
	else if (!ft_strncmp(str, "pb", 2) && ft_strlen(str) == 3)
		pb(stack_a, stack_b);
	else if (!ft_strncmp(str, "rrr", 3) && ft_strlen(str) == 4)
		rrr(stack_a, stack_b);
	else if (!ft_strncmp(str, "rr", 2) && ft_strlen(str) == 3)
		rr(stack_a, stack_b);
	else if (!ft_strncmp(str, "ss", 2) && ft_strlen(str) == 3)
		ss(stack_a, stack_b);
	else
		return (0);
	return (1);
}

void	checker(t_list **stack_a, t_list **stack_b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		if (make_action(stack_a, stack_b, str))
			free(str);
		else
		{
			free(str);
			ft_putstr_fd("Error\n", 1);
			return ;
		}
		str = get_next_line(0);
	}
	if (ft_criteria(*stack_a) == ft_lstsize(*stack_a) - 1 && *stack_b == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_putstr_fd("Got this:\n", 1);
	ft_lstputnbr(*stack_a);
}

int	main(int argc, char const *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = 0;
	stack_b = 0;
	if (argc > 1 && args_control(argc - 1, argv) == 1)
		stack_a = create_stack(argc - 1, argv, 0);
	if (stack_a && check_args(stack_a))
		checker(&stack_a, &stack_b);
	ft_lstclear(&stack_a, &free);
	ft_lstclear(&stack_b, &free);
	return (0);
}
