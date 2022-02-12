#include "checker.h"

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

void    make_action(t_list **stack_a, t_list **stack_b, char *str)
{
    if (!ft_strncmp(str, "sa", 2))
        sa(stack_a);
    else if (!ft_strncmp(str, "sb", 2))
        sb(stack_b);
    else if (!ft_strncmp(str, "rra", 3))
        rra(stack_a);
    else if (!ft_strncmp(str, "rrb", 3))
        rrb(stack_b);
    else if (!ft_strncmp(str, "ra", 2))
        ra(stack_a);
    else if (!ft_strncmp(str, "rb", 2))
        rb(stack_b);
    else if (!ft_strncmp(str, "pa", 2))
        pa(stack_a, stack_b);
    else if (!ft_strncmp(str, "pb", 2))
        pb(stack_a, stack_b);
    else if (!ft_strncmp(str, "rrr", 3))
        rrr(stack_a, stack_b);
    else if (!ft_strncmp(str, "rr", 2))
        rr(stack_a, stack_b);
    else if (!ft_strncmp(str, "ss", 2))
        ss(stack_a, stack_b);
}

void    checker(t_list **stack_a, t_list **stack_b)
{
    char *str;

    str = get_next_line(0);
    while (str)
    {
        make_action(stack_a, stack_b, str);
        free(str);
        str = get_next_line(0);
    }
	if (ft_criteria(*stack_a) == ft_lstsize(*stack_a) - 1)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_putstr_fd("Got this:\n", 1);
	ft_lstputnbr(*stack_a);
}

int main(int argc, char const *argv[])
{
    t_list  *stack_a;
    t_list  *stack_b;
    int     size;

    stack_a = 0;
    stack_b = 0;
    if (argc > 1 && args_control(argc - 1, argv) == 1)
        stack_a = create_stack(argc - 1, argv, 0);
    if (stack_a && check_args(stack_a))
        checker(&stack_a, &stack_b);
    ft_lstclear(&stack_a, &free);
    return (0);
}