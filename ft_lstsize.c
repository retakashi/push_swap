/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:12:55 by rtakashi          #+#    #+#             */
/*   Updated: 2023/04/18 22:44:45 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *node)
{
	int		cnt;
	t_list	*head;

	cnt = 0;
	head = node;
	if (node == NULL)
		return (0);
	while (!(node->next == head))
	{
		node = node->next;
		cnt++;
	}
	cnt++;
	return (cnt);
}
