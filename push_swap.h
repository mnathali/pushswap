/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:03:33 by mnathali          #+#    #+#             */
/*   Updated: 2022/02/13 15:03:34 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <unistd.h>
# include <limits.h>

void		sa(t_list **stack_a);
void		sb(t_list **stack_b);
void		ss(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
void		pa(t_list **stack_a, t_list **stack_b);
void		rrr(t_list **stack_a, t_list **stack_b);
void		rrb(t_list **stack_b);
void		rra(t_list **stack_a);
void		rr(t_list **stack_a, t_list **stack_b);
void		rb(t_list **stack_b);
void		ra(t_list **stack_a);
short		args_control(int argc, char const *argv[]);
short		check_args(t_list *stack);
t_list		*create_stack(int argc, char const *argv[], t_list *stack_a);
void		ft_sorting(t_list **stack_a);
int			mediana(t_list *stack);
int			path_to_number(t_list *stack, char index, int med);
long long	ft_atoi_long(const char *str);
int			ft_criteria(t_list *stack);
int			evaluate_sw(t_list *stack);
int			evaluate_r(t_list *stack);
int			evaluate_rr(t_list *stack);
void		double_action(t_list **s, void (*f1)(t_list **),
				void (*f2)(t_list **));
int			evaluate_r_s(t_list *stack);
int			evaluate_s_r(t_list *stack);
int			evaluate_rr_s(t_list *stack);
int			evaluate_s_rr(t_list *stack);
int			evaluate(t_list *stack_a, char *str);
int			take_back(t_list *stack);
int			min_value(t_list *stack);
int			max_value(t_list *stack);
int			nearer(t_list *stack, int med);
int			count_rs_rrs(t_list *stack_a, int content, int min, int max);
void		ft_pa_pa(t_list **stack_a, t_list **stack_b);
void		ft_pa(t_list **stack_a, t_list **stack_b);
void		complex_sort(t_list **s, int (*f)(t_list *, char *),
				int (*f_2)(t_list *));
void		complex_sort_b(t_list **s, int (*f)(t_list *, char *),
				int (*f_2)(t_list *));
void		bigger_half(t_list **stack_a, t_list **stack_b);
void		recoursion_isolate(t_list **stack_d, t_list **stack_a, short sign);
void		recoursion(t_list **stack_a, int size);

#endif
