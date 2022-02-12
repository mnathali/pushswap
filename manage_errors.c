#include "push_swap.h"

static short	lenght_of_arg(char const *str)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (str[i] != 0)
	{
		if (str[i] == ' ')
			n = 0;
		if (n > 15)
			return (0);
		n++;
		i++;
	}
	return (n);
}

short	args_control(int argc, char const *argv[])
{
    int	i;

	while (argc > 0)
	{
		i = 0;
		if (!lenght_of_arg(argv[argc]))
		{
			ft_putstr_fd("Error\n", 1);
				return (0);
		}
		while (argv[argc][i] != '\0')
		{
			if ((!ft_isdigit(argv[argc][i]) && argv[argc][i] != ' ')
			&& ((argv[argc][i] == '-' || argv[argc][i] == '+')
			&& !ft_isdigit(argv[argc][i + 1])))
			{
				ft_putstr_fd("Error\n", 1);
				return (0);
			}
			i++;
		}
		argc--;
	}
	return (1);
}

short	check_args(t_list *stack)
{
	t_list	*lst;

	while (stack)
	{
		lst = stack;
		while (lst)
		{
			if (*(long long *)lst->content > INT_MAX
			|| *(long long *)lst->content < INT_MIN)
			{
				ft_putstr_fd("Error\n", 1);
				return (0);
			}
			lst = lst->next;
			if (lst && *(int *)lst->content == *(int *)stack->content)
			{
				ft_putstr_fd("Error\n", 1);
				return (0);
			}
		}
		stack = stack->next;
	}
	return (1);
}