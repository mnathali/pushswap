/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:44:12 by mnathali          #+#    #+#             */
/*   Updated: 2022/02/13 14:44:15 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	free_array(char **par)
{
	int	i;

	i = 0;
	while (par && par[i] != 0)
	{
		free(par[i]);
		i++;
	}
	if (par)
		free(par);
}

size_t	ft_arrlen(char	**arr)
{
	size_t	i;

	if (!arr)
		return (-1);
	i = 0;
	while (arr[i] != 0)
		i++;
	return (i);
}

t_list	*free_arr_list(t_list **stack_a, char **par, void *value)
{
	if (value)
		free(value);
	ft_lstclear(stack_a, &free);
	if (par)
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
			value = malloc(sizeof(long long));
			if (!value || !par)
				return (free_arr_list(&stack_a, par, value));
			*value = ft_atoi_long(par[i]);
			new_elem = ft_lstnew(value);
			if (!new_elem)
				return (free_arr_list(&stack_a, par, value));
			ft_lstadd_front(&stack_a, new_elem);
		}
		free_array(par);
		argc--;
	}
	return (stack_a);
}
