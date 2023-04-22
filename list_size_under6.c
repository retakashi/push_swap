/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size_under6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:04:09 by rtakashi          #+#    #+#             */
/*   Updated: 2023/04/20 22:06:28 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sort_size2(t_list *head, int flg)
{
	t_list	*next;

	next = head->next;
	if ((head->cie > next->cie) && flg == 0)
		list_swap(head, next, flg);
	else if ((head->cie < next->cie) && flg == 1)
		list_swap(head, next, flg);
	return (head);
}

t_list	*sort_size3(t_list *node, int flg)
{
	int		arr[3];
	int		i;
	int		max;
	t_list	*head;

	head = node;
	i = 0;
	max = 0;
	while (i < 3)
	{
		arr[i] = node->cie;
		if (max < arr[i])
			max = arr[i];
		node = node->next;
		i++;
	}
	if (flg == 0)
		head = sort_list_ascending(head, max, arr, flg);
	else
		head = sort_list_descending(head, max, arr, flg);
	return (head);
}

static void	move_to_b_stack(t_list **a_stack, t_list **b_stack, int i_max)
{
	int	i;

	i = 0;
	while (i < i_max)
	{
		if (ft_lstsize(*a_stack) == (i_max - 3))
			break ;
		if ((*a_stack)->cie <= (i_max - 3))
			pre_list_push(a_stack, b_stack, 1);
		else
			list_rotate(a_stack, b_stack, 0);
		i++;
	}
}

static void	return_to_a_stack(t_list **a_stack, t_list **b_stack, int i_max)
{
	int	i;

	i = i_max - 3;
	while (i > 0)
	{
		pre_list_push(b_stack, a_stack, 0);
		i--;
	}
	*b_stack = NULL;
}

t_list	*sort_size_4to6(t_list *a_stack, int i_max)
{
	t_list	*b_stack;

	b_stack = NULL;
	if (i_max == 6)
	{
		move_to_b_stack(&a_stack, &b_stack, i_max);
		b_stack = sort_size3(b_stack, 1);
		a_stack = sort_size3(a_stack, 0);
	}
	else if (i_max == 5)
	{
		move_to_b_stack(&a_stack, &b_stack, i_max);
		b_stack = sort_size2(b_stack, 1);
		a_stack = sort_size3(a_stack, 0);
	}
	else
	{
		move_to_b_stack(&a_stack, &b_stack, i_max);
		a_stack = sort_size3(a_stack, 0);
	}
	return_to_a_stack(&a_stack, &b_stack, i_max);
	return (a_stack);
}
