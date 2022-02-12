#include "push_swap.h"

int ft_criteria(t_list *stack)
{
    int n;
    t_list *lst;

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

void complex_sort_b(t_list **s, int (*f)(t_list *, char *), int (*f_2)(t_list *))
{
    if (f(*s, "s_rr") < f_2(*s) && f(*s, "s_rr") < f(*s, "r_s")
    && f(*s, "s_rr") < f(*s, "s_r") && f(*s, "s_rr") < f(*s, "rr_s")
    && f(*s, "s_rr") < f(*s, "s") && f(*s, "s_rr") < f(*s, "r")
    && f(*s, "s_rr") < f(*s, "rr"))
        double_action(s, &sb, &rrb);
    else if (f(*s, "r_s") < f_2(*s) && f(*s, "r_s") < f(*s, "s_r")
    && f(*s, "r_s") < f(*s, "rr_s") && f(*s, "r_s") < f(*s, "s")
    && f(*s, "r_s") < f(*s, "r") && f(*s, "r_s") < f(*s, "rr"))
        double_action(s, &rb, &sb);
    else if (f(*s, "s_r") < f_2(*s)
    && f(*s, "s_r") < f(*s, "rr_s") && f(*s, "s_r") < f(*s, "s")
    && f(*s, "s_r") < f(*s, "r") && f(*s, "s_r") < f(*s, "rr"))
        double_action(s, &sb, &rb);
    else if (f(*s, "rr_s") < f_2(*s) && f(*s, "rr_s") < f(*s, "s")
    && f(*s, "rr_s") < f(*s, "r") && f(*s, "rr_s") < f(*s, "rr"))
        double_action(s, &rrb, &sb);
    else if (f(*s, "s") < f_2(*s)
    && f(*s, "s") < f(*s, "r") && f(*s, "s") < f(*s, "rr"))
        sb(s);
    else if (f(*s, "r") < f_2(*s) && f(*s, "r") < f(*s, "rr"))
        rb(s);
    else if (f(*s, "rr") < f_2(*s))
        rrb(s);
}

void complex_sort(t_list **s, int (*f)(t_list *, char *), int (*f_2)(t_list *))
{
    if (f(*s, "s_rr") > f_2(*s) && f(*s, "s_rr") > f(*s, "r_s")
    && f(*s, "s_rr") > f(*s, "s_r") && f(*s, "s_rr") > f(*s, "rr_s")
    && f(*s, "s_rr") > f(*s, "s") && f(*s, "s_rr") > f(*s, "r")
    && f(*s, "s_rr") > f(*s, "rr"))
        double_action(s, &sa, &rra);
    else if (f(*s, "r_s") > f_2(*s) && f(*s, "r_s") > f(*s, "s_r")
    && f(*s, "r_s") > f(*s, "rr_s") && f(*s, "r_s") > f(*s, "s")
    && f(*s, "r_s") > f(*s, "r") && f(*s, "r_s") > f(*s, "rr"))
        double_action(s, &ra, &sa);
    else if (f(*s, "s_r") > f_2(*s)
    && f(*s, "s_r") > f(*s, "rr_s") && f(*s, "s_r") > f(*s, "s")
    && f(*s, "s_r") > f(*s, "r") && f(*s, "s_r") > f(*s, "rr"))
        double_action(s, &sa, &ra);
    else if (f(*s, "rr_s") > f_2(*s) && f(*s, "rr_s") > f(*s, "s")
    && f(*s, "rr_s") > f(*s, "r") && f(*s, "rr_s") > f(*s, "rr"))
        double_action(s, &rra, &sa);
    else if (f(*s, "s") > f_2(*s)
    && f(*s, "s") > f(*s, "r") && f(*s, "s") > f(*s, "rr"))
        sa(s);
    else if (f(*s, "r") > f_2(*s) && f(*s, "r") > f(*s, "rr"))
        ra(s);
    else if (f(*s, "rr") > f_2(*s))
        rra(s);
}

void   	ft_sorting(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (ft_criteria(*stack_a) == size - 1 && *stack_b == 0)
		return ;
	recoursion(stack_a, size);
	while (*(int *)(*stack_a)->content != min_value(*stack_a))
		rra(stack_a);   
	return ;
}