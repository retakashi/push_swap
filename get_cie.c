/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cie.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:54:37 by rtakashi          #+#    #+#             */
/*   Updated: 2023/04/20 22:35:41 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*set_cie(t_list *node, int i)
{
	node->cie = i + 1;
	node = node->next;
	return (node);
}

void	binary_search_cie(int *int_arr, t_list *node, int min, int *max)
{
	int	i;
	int	tmp_max;
	int	mid;

	i = 0;
	tmp_max = *max;
	while (++i <= tmp_max + 1)
	{
		min = 0;
		*max = tmp_max;
		while (min <= *max)
		{
			mid = (min + *max) / 2;
			if (node->num == int_arr[mid])
			{
				node = set_cie(node, mid);
				break ;
			}
			if (node->num < int_arr[mid])
				*max = mid;
			else
				min = mid + 1;
		}
	}
	*max = tmp_max;
}
