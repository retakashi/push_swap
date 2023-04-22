/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_int_arr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:04:08 by reira             #+#    #+#             */
/*   Updated: 2023/04/20 22:40:41 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	arr_copy(int *int_arr, int left, int right, int *sort)
{
	int	l;
	int	i;

	l = left;
	i = 0;
	while (l <= right)
	{
		int_arr[l] = sort[i];
		l++;
		i++;
	}
}

static int	merge_sort(int *int_arr, int left, int mid, int right)
{
	int	*sort;
	int	i;
	int	l;
	int	r;

	i = 0;
	l = left;
	r = mid + 1;
	sort = malloc(sizeof(int) * (right + 1));
	if (sort == NULL)
		return (-1);
	while (l <= mid && r <= right)
	{
		if (int_arr[l] < int_arr[r])
			sort[i++] = int_arr[l++];
		else
			sort[i++] = int_arr[r++];
	}
	while (l <= mid)
		sort[i++] = int_arr[l++];
	while (r <= right)
		sort[i++] = int_arr[r++];
	arr_copy(int_arr, left, right, sort);
	return (0);
}

void	m_sort_partition(int *int_arr, int left, int right)
{
	int	mid;
	int	n;

	mid = (left + right) / 2;
	if (left < right)
	{
		m_sort_partition(int_arr, left, mid);
		m_sort_partition(int_arr, mid + 1, right);
		n = merge_sort(int_arr, left, mid, right);
		if (n == -1)
		{
			free(int_arr);
			int_arr = NULL;
		}
	}
}

int	sort_ascending_and_arror_check(int *arr, int max)
{
	int	i;
	int	j;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < max)
	{
		j = i + 1;
		while (j <= max)
		{
			if (arr[i] > arr[j])
				cnt++;
			if (arr[i] == arr[j])
				return (-1);
			j++;
		}
		i++;
	}
	if (cnt == 0)
		return (0);
	return (max);
}
