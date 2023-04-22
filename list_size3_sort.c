/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size3_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:53:34 by rtakashi          #+#    #+#             */
/*   Updated: 2023/04/20 22:10:45 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sort_list_ascending(t_list *head, int max, int arr[], int flg)
{
	if (arr[0] == max - 2 && arr[1] > arr[2])
	{
		head = list_reverse_rotate(head, flg);
		list_swap(head, head->next, flg);
	}
	else if (arr[0] == max - 1 && arr[1] > arr[2])
		head = list_reverse_rotate(head, flg);
	else if (arr[0] == max - 1 && arr[1] < arr[2])
		list_swap(head, head->next, flg);
	else if (arr[0] == max && arr[1] > arr[2])
	{
		list_swap(head, head->next, flg);
		head = list_reverse_rotate(head, flg);
	}
	else if (arr[0] == max && arr[1] < arr[2])
		list_rotate(&head, NULL, flg);
	return (head);
}

t_list	*sort_list_descending(t_list *head, int max, int arr[], int flg)
{
	if (arr[0] == max - 2 && arr[1] < arr[2])
	{
		list_swap(head, head->next, flg);
		head = list_reverse_rotate(head, flg);
	}
	else if (arr[0] == max - 2 && arr[1] > arr[2])
		list_rotate(NULL, &head, flg);
	else if (arr[0] == max - 1 && arr[1] < arr[2])
		head = list_reverse_rotate(head, flg);
	else if (arr[0] == max - 1 && arr[1] > arr[2])
		list_swap(head, head->next, flg);
	else if (arr[0] == max && arr[1] < arr[2])
	{
		head = list_reverse_rotate(head, flg);
		list_swap(head, head->next, flg);
	}
	return (head);
}
