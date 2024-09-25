/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:07:52 by rtakashi          #+#    #+#             */
/*   Updated: 2023/05/03 17:55:18 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	put_error(int *arr, t_list **stack)
{
	int		i;
	t_list	*node_next;

	i = 0;
	if (arr != NULL)
		free(arr);
	if (stack != NULL && *stack != NULL)
	{
		while ((*stack)->next != NULL)
		{
			node_next = (*stack)->next;
			free(*stack);
			*stack = NULL;
			*stack = node_next;
		}
		node_next = (*stack)->next;
		free(*stack);
		*stack = NULL;
		*stack = node_next;
		stack = NULL;
	}
	write(2, "Error\n", 6);
	return (-1);
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

int	ft_free(int *arr, t_list **stack)
{
	int		i;
	t_list	*node_next;

	i = 0;
	if (arr != NULL)
	{
		free(arr);
		arr = NULL;
	}
	if (stack != NULL && *stack != NULL)
	{
		i = ft_lstsize(*stack);
		while (i > 0)
		{
			node_next = (*stack)->next;
			free(*stack);
			*stack = NULL;
			*stack = node_next;
			i--;
		}
		stack = NULL;
	}
	return (0);
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q push_swap");
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
	node = NULL;
	ret = args_error_check(argc, argv);
	if (ret == -1)
		return (put_error(int_arr, NULL));
	ret = get_int_arr(argc, argv, &int_arr, &i_max);
	if (ret == -1)
		return (put_error(int_arr, NULL));
	if (i_max == 0)
		return (ft_free(int_arr, NULL));
	ret = get_node(argc, argv, &node);
	if (ret == -1)
		return (put_error(int_arr, &node));
	binary_search_cie(int_arr, node, 0, &i_max);
	free(int_arr);
	i_max++;
	push_swap(node, i_max);
	return (0);
}
