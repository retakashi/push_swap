/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_error_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reira <reira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:41:38 by reira             #+#    #+#             */
/*   Updated: 2024/10/03 16:12:40 by reira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	argc2_get_number(char *argv, int i, char *str)
{
	int	j;

	j = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] == '-' || argv[i] == '+')
			str[j++] = argv[i++];
		if (!ft_isdigit(argv[i]))
			return (-1);
		while (ft_isdigit(argv[i]))
		{
			str[j++] = argv[i++];
			if (j > 11)
				return (-1);
		}
		str[j] = '\0';
		if (argv[i] == ' ' && argv[i + 1] != '\0')
		{
			i++;
			break ;
		}
	}
	return (i);
}

static int	case_argc_over2(int argc, char **argv)
{
	int	i;
	int	error_flg;

	i = 1;
	error_flg = 0;
	if (argc > 2)
	{
		while (argv[i] != NULL)
		{
			ft_atoi_intver(argv[i], &error_flg);
			if (error_flg == -1)
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
	int		error_flg;

	i = 0;
	error_flg = 0;
	while (argv[i] != '\0')
	{
		i = argc2_get_number(argv, i, str);
		if (i == -1)
			return (-1);
		ft_atoi_intver(str, &error_flg);
		if (error_flg == -1)
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
