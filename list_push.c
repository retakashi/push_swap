/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:47:45 by rtakashi          #+#    #+#             */
/*   Updated: 2023/04/20 22:24:16 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_push(int flg)
{
	if (flg == 0)
		put_operations("pa");
	else
		put_operations("pb");
}

static void	list_push_receive_null(t_list **push, t_list **receive, int flg)
{
	t_list	*push_head;
	t_list	*push_tail;

	push_head = (*push)->next;
	push_tail = (*push)->prev;
	*receive = *push;
	(*receive)->next = *push;
	(*receive)->prev = *push;
	*push = push_head;
	(*push)->prev = push_tail;
	push_tail->next = push_head;
	if (flg == 0)
		put_operations("pa");
	else
		put_operations("pb");
}

static void	list_push_size1(t_list **push, t_list **receive, int flg)
{
	t_list	*receive_next;
	t_list	*receive_tail;

	receive_next = *receive;
	receive_tail = (*receive)->prev;
	*receive = *push;
	receive_next->prev = *receive;
	(*receive)->next = receive_next;
	(*receive)->prev = receive_tail;
	receive_tail->next = *receive;
	*push = NULL;
	if (flg == 0)
		put_operations("pa");
	else
		put_operations("pb");
}

static void	list_push(t_list **push, t_list **receive, int flg)
{
	t_list	*receive_next;
	t_list	*receive_tail;
	t_list	*push_head;
	t_list	*push_tail;

	if (ft_lstsize(*push) == 1)
		list_push_size1(push, receive, flg);
	else
	{
		receive_next = *receive;
		receive_tail = (*receive)->prev;
		push_head = (*push)->next;
		push_tail = (*push)->prev;
		*receive = *push;
		receive_next->prev = *receive;
		(*receive)->next = receive_next;
		(*receive)->prev = receive_tail;
		receive_tail->next = *receive;
		*push = push_head;
		(*push)->prev = push_tail;
		push_tail->next = *push;
		put_push(flg);
	}
}

void	pre_list_push(t_list **push, t_list **receive, int flg)
{
	if (*receive == NULL)
	{
		list_push_receive_null(push, receive, flg);
		return ;
	}
	else
		list_push(push, receive, flg);
}
