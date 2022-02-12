#include "push_swap.h"
#include "checker.h"

int	ft_criteria(t_list *stack)
{
	int		n;
	t_list	*lst;

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