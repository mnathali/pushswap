#include "push_swap.h"

long long	ft_atoi_long(const char *str)
{
	size_t		i;
	long long	j;
	short		sign;

	i = 0;
	j = 0;
	sign = 1;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (j * 10 + (sign * (str[i] - '0')) < j && sign > 0)
			return (-1);
		if (j * 10 + (sign * (str[i] - '0')) > j && sign < 0)
			return (0);
		j = j * 10 + (sign * (str[i] - '0'));
		i++;
	}
	return (j);
}

int take_back(t_list *stack)
{
    while (stack->next)
        stack = stack->next;
    return(*(int *)stack->content);
}

void bigger_half(t_list **stack_a, t_list **stack_b)
{
    int med;
    int sz;
    med = mediana(*stack_b);
    sz = ft_lstsize(*stack_b);
    while (sz)
    {
        if (*(int *)(*stack_b)->content >= med)
            pa(stack_a, stack_b);
        else 
           rb(stack_b);
        sz--;
    }
}

int	where_min_max(t_list *stack_a, int min_max)
{
	int	n;

	n = 0;
	while (*(int *)stack_a->content != min_max)
	{
		n++;
		stack_a = stack_a->next;
	}
	return (n);
}

int count_rs_rrs(t_list *stack_a, int content, int min, int max)
{
	int n;

	n = 0;
	if (content > max)
		return (where_min_max(stack_a, max));
	if (content < min)
		return (where_min_max(stack_a, min));
	while (content < *(int *)stack_a->content)
	{
		n++;
		stack_a = stack_a->next;
	}
	while (stack_a && content > *(int *)stack_a->content)
	{
		n++;
		stack_a = stack_a->next;
	}
	return (n);
}