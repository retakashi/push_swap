/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:41:38 by reira             #+#    #+#             */
/*   Updated: 2023/04/02 22:22:47 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

int	argv_words_count(char *argv)
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

void	argc2_set_str(char *str, char *argv)
{
	int	j;

	j = 0;
	if (*argv == '-')
	{
		*str = '-';
		str++;
		argv++;
	}
	while (*argv >= '0' && *argv <= '9' && *argv != '\0')
	{
		*str = *argv;
		str++;
		argv++;
	}
	*str = '\0';
	if (*argv == ' ' && *(argv++) != '\0')
		argv++;
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

int	argc_2(char *argv)
{
	char	str[12];
	int		*int_arr;
	int		i;
	int		n;

	i = 0;
	n=argv_words_count(argv);
	int_arr = malloc(sizeof(int) * n);
	while (i<n&&*argv != '\0')
	{
		argc2_set_str(str, argv);
		int_arr[i] = ft_atoi_intver(str);
		n = int_check(str, &int_arr[i]);
		if (n == -1)
			return (-1);
		i++;
	}
	return (i);
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

int	args_error(int argc, int **argv)
{
	int n;

	n = 0;
	if (argc == 2)
	{
		n = argc_2(argv[1]);
		return(-1);
	}
	
}
