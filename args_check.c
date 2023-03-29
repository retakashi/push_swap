/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reira <reira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:41:38 by reira             #+#    #+#             */
/*   Updated: 2023/03/29 23:03:20 by reira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static size_t	check_space(const char *str, size_t i);
static size_t	check_sign(const char *str, size_t i, int *neg);

int	argv_word_count(char *argv)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] == '-')
			i++;
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return (-1);
		while (argv[i] >= '0' && argv[i] <= '9')
			i++;
		cnt++;
		if (argv[i] == ' ')
			i++;
	}
	return (cnt);
}

int	ft_atoi_intver(const char *str)
{
	size_t	i;
	int		neg;
	long	num;

	i = 0;
	neg = 0;
	i = check_sign(str, i, &neg);
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((neg == 0 && num > INT_MAX / 10) || (neg == 0 && num == INT_MAX / 10
				&& (str[i] - '0') > INT_MAX % 10))
			return (1);
		if ((neg == 1 && num > INT_MIN / 10 * -1) || (neg == 1 && num == INT_MIN
				/ 10 * -1 && (str[i] - '0') > INT_MIN % 10 * -1))
			return (-1);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (neg == 1)
		num = num * -1;
	return ((int)num);
}

static size_t	check_sign(const char *str, size_t i, int *neg)
{
	if (str[i] == '-')
	{
		*neg += 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	return (i);
}

int	argc2_set_str(char *str, char *argv, int i)
{
	int	j;

	j = 0;
	if (argv[i] == '-')
	{
		str[j++] = '-';
		i++;
	}
	while (argv[i] >= '0' && argv[i] <= '9' && argv[i] != '\0')
		str[j++] = argv[i++];
	str[j] = '\0';
	if (argv[i] == ' ' && argv[i + 1] != '\0')
		i++;
	return (i);
}

int	int_check(char *str, int *int_arr)
{
	if (*int_arr == -1 && !(str[0] == '-' && str[1] == '1' && str[2] == '\0'))
		return (-1);
	if (*int_arr == 1 && !(str[0] == '1' && str[1] == '\0'))
		return (-1);
	if (*int_arr == 0 && !(str[0] == '0' && str[1] == '\0'))
		return (-1);
	return (0);
}

int	argc_2(int *int_arr, char argv[])
{
	char	str[12];
	int		i;
	int		j;
	int		n;

	i = 0;
	j = 0;
	while (argv[i] != '\0')
	{
		i = argc2_set_str(str, argv, i);
		int_arr[j] = ft_atoi_intver(str);
		n = int_check(str, &int_arr[j]);
		if (n == -1)
			return (-1);
		j++;
	}
	return (j);
}

int	change_int(int argc, int *int_arr, char *argv[])
{
	int	i;
	int	j;
	int	n;

	i = 1;
	j = 0;
	while (argv[i] != NULL)
	{
		int_arr[j] = ft_atoi_intver(argv[i]);
		n = int_check(argv[i], &int_arr[j]);
		if (n == -1)
			return (-1);
		i++;
		j++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int *arr;
	int i;
	int j;
	int cnt;
	// int argc = 2;
	// char *argv[2] = {"a.out", "2147483647 3 4"};
	if (argc == 0 || argc == 1)
		return (0);
	i=0;
	if (argc == 2)
	{
		cnt = argv_word_count(argv[1]);
		if (cnt < 2)
			return (printf("Error\n"));
		arr = malloc(sizeof(int) * cnt);
		if (arr == NULL)
			return (printf("Error\n"));
		cnt = argc_2(arr, argv[1]);
		printf("cnt:%d", cnt);
		if (cnt == -1)
			return (printf("Error\n"));
	}
	else
	{
		arr = malloc(sizeof(int) * (argc - 1));
		if (arr == NULL)
			return (printf("Error\n"));
		cnt = change_int(argc, arr, argv);
		if (cnt == -1)
			return (printf("Error\n"));
	}
	j = 0;
	i = 0;
	if (argc == 2)
	{
		while (i < cnt)
		{
			printf("arr[%d] %d\n", i, arr[i]);
			i++;
		}
	}
	else
	{
		while (i < argc - 1)
		{
			printf("int[%d] %d\n", i, arr[i]);
			i++;
		}
	}
	return (0);
}