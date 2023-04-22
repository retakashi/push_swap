/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_error_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:41:38 by reira             #+#    #+#             */
/*   Updated: 2023/04/20 23:09:28 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	argc2_get_number(char *argv, int i, char *str)
{
	int	j;

	j = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] == ' ' && argv[i + 1] != '\0')
			i++;
		if (argv[i] == '-' || argv[i] == '+')
			i++;
		if (!ft_isdigit(argv[i]))
			return (-1);
		while (ft_isdigit(argv[i]))
		{
			str[j] = argv[i];
			i++;
			j++;
			if (j > 11)
				return (-1);
		}
		str[j] = '\0';
		if (argv[i] == ' ' && argv[i + 1] != '\0')
			break ;
	}
	return (i);
}

static int	int_check(char *str, int num)
{
	if (num == -1 && !(str[0] == '-' && str[1] == '1' && str[2] == '\0'))
		return (-1);
	if (num == 1 && !(str[0] == '1' && str[1] == '\0'))
		return (-1);
	if (num == 0 && !(str[0] == '0' && str[1] == '\0'))
		return (-1);
	return (0);
}

static int	case_argc_over2(int argc, char **argv)
{
	int	i;
	int	num;

	i = 1;
	if (argc > 2)
	{
		while (argv[i] != NULL)
		{
			num = ft_atoi_intver(argv[i]);
			num = int_check(argv[i], num);
			if (num == -1)
				return (-1);
			i++;
		}
	}
	return (0);
}

static int	case_argc_2(char *argv)
{
	char	str[13];
	int		i;
	int		num;
	int		ret;

	i = 0;
	while (argv[i] != '\0')
	{
		i = argc2_get_number(argv, i, str);
		if (i == -1)
			return (-1);
		num = ft_atoi_intver(str);
		if (num == -1)
			return (-1);
		ret = int_check(str, num);
		if (ret == -1)
			return (-1);
	}
	return (0);
}

int	args_error_check(int argc, char **argv)
{
	int	ret;

	if (argc == 2)
		ret = case_argc_2(argv[1]);
	else
		ret = case_argc_over2(argc, argv);
	if (ret == -1)
		return (-1);
	return (ret);
}
