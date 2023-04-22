/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size_over6_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:16:29 by rtakashi          #+#    #+#             */
/*   Updated: 2023/04/20 22:20:16 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_cie_max(t_list *stack)
{
	int	cnt;
	int	max;

	cnt = ft_lstsize(stack);
	max = 0;
	while (cnt > 0)
	{
		if (max < stack->cie)
			max = stack->cie;
		stack = stack->next;
		cnt--;
	}
	return (max);
}

void	optimization_rotate_a(t_list **a_stack, t_list **b_stack, int max)
{
	if (*a_stack != NULL && (*a_stack)->cie > max
		&& (*a_stack)->prev->cie <= max)
		*a_stack = list_reverse_rotate(*a_stack, 0);
	else
		list_rotate(a_stack, b_stack, 0);
}

void	optimization_rotate_b(t_list **a_stack, t_list **b_stack, int max)
{
	if ((*b_stack != NULL && ft_lstsize(*b_stack) > 1) && (*a_stack != NULL
			&& (*a_stack)->cie > max))
		list_rotate(a_stack, b_stack, 2);
	else if (*b_stack != NULL && ft_lstsize(*b_stack) > 1)
		list_rotate(a_stack, b_stack, 1);
}

static void	sort_a(t_list **a_stack, t_list **b_stack, int tmp_max)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while ((*a_stack)->cie <= (tmp_max - 1))
	{
		list_rotate(a_stack, b_stack, 0);
		cnt++;
	}
	pre_list_push(b_stack, a_stack, 0);
	while (i < cnt)
	{
		*a_stack = list_reverse_rotate(*a_stack, 0);
		i++;
	}
}

int	pre_sort_a(t_list **a_stack, t_list **b_stack, int tmp_max)
{
	if (*a_stack == NULL || (*a_stack)->cie > (*b_stack)->cie)
		pre_list_push(b_stack, a_stack, 0);
	else if (ft_lstsize(*a_stack) == 2)
	{
		pre_list_push(b_stack, a_stack, 0);
		*a_stack = sort_size3(*a_stack, 0);
	}
	else if ((*b_stack)->cie > get_cie_max(*a_stack))
	{
		pre_list_push(b_stack, a_stack, 0);
		list_rotate(a_stack, b_stack, 0);
		tmp_max = (*a_stack)->cie - 1;
	}
	else if ((*b_stack)->cie == tmp_max && (*a_stack)->cie == (tmp_max - 1))
	{
		pre_list_push(b_stack, a_stack, 0);
		list_swap(*a_stack, (*a_stack)->next, 0);
	}
	else
		sort_a(a_stack, b_stack, tmp_max);
	return (get_cie_max(*b_stack));
}
