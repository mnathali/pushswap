/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:03:05 by mnathali          #+#    #+#             */
/*   Updated: 2022/02/13 15:03:07 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char const *argv[])
{
	t_list	*stack_a;

	stack_a = 0;
	if (argc > 1 && args_control(argc - 1, argv) == 1)
		stack_a = create_stack(argc - 1, argv, 0);
	if (stack_a && check_args(stack_a))
		ft_sorting(&stack_a);
	ft_lstclear(&stack_a, &free);
	return (0);
}
