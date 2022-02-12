#include "push_swap.h"

void	double_action(t_list **stack_a, void (*f_1)(t_list **), void (*f_2)(t_list **))
{
	f_1(stack_a);
	f_2(stack_a);
}

int evaluate_sw(t_list *stack)
{
	int		n;
	t_list	*lst;

	lst = stack;
	n = 0;
	if (!lst || !lst->next)
		return (0);
	lst = (lst->next)->next;
	if (*(int *)(stack->next)->content > *(int *)stack->content)
		n--;
	else
		n++;
	if (lst && *(int *)lst->content > *(int *)stack->content)
		n++;
	else
		n--;
	if (lst)
		n = n + ft_criteria(lst);
	return (n);
}

int	evaluate_r(t_list *stack)
{
	int		n;
	t_list	*lst;

	lst = stack;
	n = 0;
	if (!lst || !lst->next)
		return (0);
	n = ft_criteria(lst->next);
	while (lst->next != 0)
		lst = lst->next;
	if (*(int *)lst->content < *(int *)stack->content)
		n++;
	else
		n--;
	return (n);
}

int	evaluate_rr(t_list *stack)
{
	int		n;
	t_list	*lst;

	lst = stack;
	n = 0;
	if (!lst || !lst->next)
		return (0);
	while ((lst->next)->next != 0)
	{
		if (*(int *)(lst->next)->content > *(int *)lst->content)
			n++;
		else
			n--;
		lst = lst->next;
	}
	if (*(int *)(lst->next)->content < *(int *)stack->content)
		n++;
	else
		n--;
	return (n);
}

int	evaluate(t_list *stack_a, char *str)
{
	int	n;

	n = 0;
	if (!ft_strncmp(str, "s", 4))
		n = evaluate_sw(stack_a);
	else if (!ft_strncmp(str, "r", 4))
		n = evaluate_r(stack_a);
	else if (!ft_strncmp(str, "rr", 4))
		n = evaluate_rr(stack_a);
	else if (!ft_strncmp(str, "s_rr", 4))
		n = evaluate_s_rr(stack_a);
	else if (!ft_strncmp(str, "r_s", 4))
		n = evaluate_r_s(stack_a);
	else if (!ft_strncmp(str, "s_r", 4))
		n = evaluate_s_r(stack_a);
	else if (!ft_strncmp(str, "rr_s", 4))
		n = evaluate_rr_s(stack_a);
	return (n);
}