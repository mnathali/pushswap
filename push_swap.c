#include "push_swap.h"

int	main(int argc, char const *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = 0;
	stack_b = 0;
	if (argc > 1 && args_control(argc - 1, argv) == 1)
		stack_a = create_stack(argc - 1, argv, 0);
	if (stack_a && check_args(stack_a))
		ft_sorting(&stack_a, &stack_b);
	ft_lstclear(&stack_a, &free);
	return (0);
}