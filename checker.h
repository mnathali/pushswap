#ifndef CHECKER_H
# define CHECKER_H
# include "libft/libft.h"
# include <unistd.h>
# define SZ 42

char		*get_next_line(int fd);
void		checker(t_list **stack_a, t_list **stack_b);

#endif