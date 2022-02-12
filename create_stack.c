#include "push_swap.h"

void	free_array(char **par)
{
	int	i;

	i = 0;
	while (par[i] != 0)
	{
		free(par[i]);
		i++;
	}
	free(par);
}

size_t	ft_arrlen(char	**arr)
{
	size_t	i;

	i = 0;
	while (arr && arr[i] != 0)
		i++;
	return (i);
}

t_list	*free_arr_list(t_list **stack_a, char **par)
{
	ft_lstclear(stack_a, &free);
	free_array(par);
	return (0);
}

t_list	*create_stack(int argc, char const *argv[], t_list *stack_a)
{
	t_list		*new_elem;
	char		**par;
	int			i;
	long long	*value;

	while (argc > 0)
	{
		par = ft_split(argv[argc], ' ');
		i = ft_arrlen(par);
		while (i != 0)
		{
			i--;
			value = malloc(sizeof(int));
			if (!value)
				return (free_arr_list(&stack_a, par));
			*value = ft_atoi_long(par[i]);
			new_elem = ft_lstnew(value);
			if (!new_elem)
				return (free_arr_list(&stack_a, par));
			ft_lstadd_front(&stack_a, new_elem);
		}
		free_array(par);
		argc--;
	}
	return (stack_a);
}