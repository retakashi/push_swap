/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reira <reira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:44:11 by rtakashi          #+#    #+#             */
/*   Updated: 2024/10/03 16:14:14 by reira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*sort_size_over6(t_list *a_stack, int i_max)
{
	t_list	*b_stack;
	int		base;
	int		num;

	b_stack = NULL;
	if (i_max < 500)
		base = 7;
	else
		base = 30;
	num = base;
	while (a_stack != NULL)
	{
		a_stack = move_to_b(&a_stack, &b_stack, base, num);
		num = num + (base * 2);
	}
	return_to_a(&a_stack, &b_stack, i_max, base);
	return (a_stack);
}

void	push_swap(t_list *a_stack, int i_max)
{
	if (i_max == 2)
		a_stack = sort_size2(a_stack, 0);
	else if (i_max == 3)
		a_stack = sort_size3(a_stack, 0);
	else if (i_max > 3 && i_max < 7)
		a_stack = sort_size_4to6(a_stack, i_max);
	else
		a_stack = sort_size_over6(a_stack, i_max);
	ft_free(NULL, &a_stack);
}
