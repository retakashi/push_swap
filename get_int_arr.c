/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:03:38 by rtakashi          #+#    #+#             */
/*   Updated: 2023/05/03 17:35:38 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_number(char *argv)
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	while (argv[i] != '\0')
	{
		if (ft_isdigit(argv[i]))
			cnt++;
		while (ft_isdigit(argv[i]))
			i++;
		while ((!ft_isdigit(argv[i])) && argv[i] != '\0')
			i++;
	}
	return (cnt);
}

static int	*get_int_arr_argc2(char *argv, int *int_arr, int *i_max)
{
	int	i;
	int	j;
	int	num;

	*i_max = count_number(argv);
	int_arr = malloc(sizeof(int) * (*i_max));
	if (int_arr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (j < *i_max)
	{
		i = get_number(argv, i, &num);
		int_arr[j] = num;
		j++;
	}
	*i_max -= 1;
	return (int_arr);
}

static int	*get_int_arr_argc_over2(int argc, char **argv, int *int_arr,
		int *i_max)
{
	int	i;

	*i_max = argc - 1;
	int_arr = malloc(sizeof(int) * *i_max);
	if (int_arr == NULL)
		return (NULL);
	i = 1;
	while (i <= *i_max)
	{
		int_arr[i - 1] = ft_atoi_intver(argv[i], 0);
		i++;
	}
	*i_max -= 1;
	return (int_arr);
}

int	get_int_arr(int argc, char **argv, int **int_arr, int *i_max)
{
	int	ret;

	ret = 0;
	if (argc == 2)
		*int_arr = get_int_arr_argc2(argv[1], *int_arr, i_max);
	else
		*int_arr = get_int_arr_argc_over2(argc, argv, *int_arr, i_max);
	if (*int_arr == NULL)
		return (-1);
	*i_max = sort_ascending_and_error_check(*int_arr, *i_max);
	if (*i_max == 0)
		return (0);
	if (*i_max == -1)
		return (-1);
	ret = m_sort_partition(*int_arr, 0, *i_max);
	return (ret);
}
