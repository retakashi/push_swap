/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_intver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:05:26 by rtakashi          #+#    #+#             */
/*   Updated: 2023/04/20 20:31:22 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_sign(const char *str, size_t i, int *neg)
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

int	ft_atoi_intver(const char *str)
{
	size_t	i;
	int		neg;
	long	num;

	i = 0;
	neg = 0;
	i = check_sign(str, i, &neg);
	num = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (-1);
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
