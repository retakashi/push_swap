/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_intver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reira <reira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:05:26 by rtakashi          #+#    #+#             */
/*   Updated: 2023/03/29 23:05:24 by reira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <stdio.h>
#include <limits.h>

static size_t	check_space(const char *str, size_t i);
static size_t	check_sign(const char *str, size_t i, int *neg);

int	ft_atoi(const char *str)
{
	size_t	i;
	int		neg;
	long	num;

	i = 0;
	neg = 0;
	i = check_space(str, i);
	i = check_sign(str, i, &neg);
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((neg == 0 && num > INT_MAX / 10) || (neg == 0 && num == INT_MAX
				/ 10 && (str[i] - '0') > INT_MAX % 10))
			return (1);
		if ((neg == 1 && num > INT_MIN / 10 * -1) || (neg == 1
				&& num == INT_MIN / 10 * -1 && (str[i] - '0') > INT_MIN % 10
				* -1))
			return (-1);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (neg == 1)
		num = num * -1;
	return ((int)num);
}

static size_t	check_space(const char *str, size_t i)
{
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
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

// #include <stdio.h>
// #include <stdlib.h>
// int	main(void)
// {
// 	printf("-----iroiro-----\n");
// 	printf("   atoi=[%d]\n", atoi("\0"));
// 	printf("ft_atoi=[%d]\n", ft_atoi("\0"));
// 	printf("   atoi=[%d]\n", atoi("-2147483648"));
// 	printf("ft_atoi=[%d]\n", ft_atoi("-2147483648"));
// 	printf("   atoi(LONG_MIN+1)=[%d]\n", atoi("-9223372036854775807"));
// 	printf("ft_atoi(LONG_MIN+1)=[%d]\n", ft_atoi("-9223372036854775807"));
// 	printf("   atoi(LONG_MAX-1)=[%d]\n", atoi("9223372036854775806"));
// 	printf("ft_atoi(LONG_MAX-1)=[%d]\n", ft_atoi("9223372036854775806"));
// 	printf("   atoi(INT_MIN-1)=[%d]\n", atoi("-2147483649"));
// 	printf("ft_atoi(INT_MIN-1)=[%d]\n", ft_atoi("-2147483649"));
// 	printf("   atoi(INT_MAX+1)=[%d]\n", atoi("2147483648"));
// 	printf("ft_atoi(INT_MAX+1)=[%d]\n", ft_atoi("2147483648"));
// 	printf("   atoi(INT_MIN-10)=[%d]\n", atoi("-2147483658"));
// 	printf("ft_atoi(INT_MIN-10)=[%d]\n", ft_atoi("-2147483658"));
// 	printf("   atoi(INT_MAX+10)=[%d]\n", atoi("2147483657"));
// 	printf("ft_atoi(INT_MAX+10)=[%d]\n", ft_atoi("2147483657"));
// 	printf("-----overflow-----\n");
// 	printf("   atoi(+1)=[%d]\n", atoi("9223372036854775808"));
// 	printf("ft_atoi(+1)=[%d]\n", ft_atoi("9223372036854775808"));
// 	printf("   atoi(一桁多い)=[%d]\n", atoi("92233720368547758000"));
// 	printf("ft_atoi(一桁多い)=[%d]\n", ft_atoi("92233720368547758000"));
// 	printf("-----underflow-----\n");
// 	printf("   atoi(-1)=[%d]\n", atoi("-9223372036854775809"));
// 	printf("ft_atoi(-1)=[%d]\n", ft_atoi("-9223372036854775809"));
// 	printf("   atoi(一桁多い)=[%d]\n", atoi("-92233720368547758000"));
// 	printf("ft_atoi(一桁多い)=[%d]\n", ft_atoi("-92233720368547758000"));
// }
