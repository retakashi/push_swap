/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:04:08 by reira             #+#    #+#             */
/*   Updated: 2023/04/02 20:00:39 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	arr_copy(int int_arr[], int left, int right, int *sort)
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

int	merge_sort(int int_arr[], int left, int mid, int right)
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
	free(sort);
	return (0);
}

void	partition(int int_arr[], int left, int right)
{
	int	mid;

	mid = (left + right) / 2;
	if (left < right)
	{
		partition(int_arr, left, mid);
		partition(int_arr, mid + 1, right);
		merge_sort(int_arr, left, mid, right);
	}
}

int	arr_error(int arr[], int max)
{
	int	i;
	int	j;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i <= max)
	{
		j = i + 1;
		while (j <= max)
		{
			if (arr[i] == arr[j])
				return (-1);
			if (arr[i] > arr[j])
				cnt++;
			j++;
		}
		i++;
	}
	if (cnt == 0)
		return (-1);
	return (0);
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q a.out");
// }

int	main(void)
{
	int	i;
	int	n;

	int	arr[10]= {9,0,1,4,5};
	i = 0;
	n = arr_error(arr, 4);
	if (n == -1)
		printf("Error\n");
	partition(arr, 0, 4);
	while (i < 5)
	{
		printf("arr[%d]: %d\n", i, arr[i]);
		i++;
	}
	return (0);
}
