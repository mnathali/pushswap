/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:42:44 by mnathali          #+#    #+#             */
/*   Updated: 2022/02/13 14:42:55 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft/libft.h"
# include <unistd.h>
# define SZ 42

char		*get_next_line(int fd);
void		checker(t_list **stack_a, t_list **stack_b);

#endif
