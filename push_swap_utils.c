/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:24:46 by reira             #+#    #+#             */
/*   Updated: 2023/04/20 21:02:01 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//push->receive

void	list_swap(t_list *a, t_list *b, int flg)
{
	int	tmp_cie;
	int	tmp_num;

	tmp_cie = a->cie;
	a->cie = b->cie;
	b->cie = tmp_cie;
	tmp_num = a->num;
	a->num = b->num;
	b->num = tmp_num;
	if (flg == 0)
		put_operations("sa");
	else
		put_operations("sb");
}

//123->231
void	list_rotate(t_list **a_stack, t_list **b_stack, int flg)
{
	if (flg == 0)
	{
		put_operations("ra");
		*a_stack = (*a_stack)->next;
	}
	else if (flg == 1)
	{
		put_operations("rb");
		*b_stack = (*b_stack)->next;
	}
	else if (flg == 2)
	{
		put_operations("rr");
		*a_stack = (*a_stack)->next;
		*b_stack = (*b_stack)->next;
	}
}

//123->312
t_list	*list_reverse_rotate(t_list *stack, int flg)
{
	t_list	*head;

	head = stack->prev;
	if (flg == 0)
		put_operations("rra");
	else
		put_operations("rrb");
	return (head);
}
