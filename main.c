/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:07:52 by rtakashi          #+#    #+#             */
/*   Updated: 2023/04/22 15:56:55 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	put_error(int *int_arr)
{
	if (int_arr != NULL)
		free(int_arr);
	int_arr = NULL;
	write(2, "Error\n", 6);
	return (1);
}

void	put_operations(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	write(1, "\n", 1);
}

void	*ft_free(int *arr, t_list **stack)
{
	t_list	*node_next;

	if (arr != NULL)
		free(arr);
	if (stack != NULL)
	{
		(*stack)->prev = NULL;
		while ((*stack)->prev != NULL)
		{
			node_next = (*stack)->next;
			free(*stack);
			*stack = NULL;
			*stack = node_next;
		}
		stack = NULL;
	}
	return ((void *)0);
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q a.out");
// }

int	main(int argc, char **argv)
{
	int		ret;
	int		*int_arr;
	t_list	*node;
	int		i_max;

	if (argc == 1)
		return (0);
	int_arr = NULL;
	ret = args_error_check(argc, argv);
	if (ret == -1)
		return (put_error(int_arr));
	int_arr = get_int_arr(argc, argv, int_arr, &i_max);
	if (i_max == 0)
		return (0);
	if (int_arr == NULL)
		return (put_error(int_arr));
	node = get_node(argc, argv);
	if (node == NULL)
		return (put_error(int_arr));
	binary_search_cie(int_arr, node, 0, &i_max);
	i_max++;
	push_swap(node, i_max);
	return (0);
}
