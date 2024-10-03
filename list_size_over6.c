/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size_over6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reira <reira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:48:43 by rtakashi          #+#    #+#             */
/*   Updated: 2024/10/03 16:13:55 by reira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	return_to_a_from_the_top(t_list **a_stack,
										t_list **b_stack,
										int *i_max,
										int base)
{
	int	tmp_max;
	int	n;

	tmp_max = *i_max;
	n = *i_max - 1;
	while (*b_stack != NULL && (*b_stack)->cie > (*i_max - base))
	{
		if ((*b_stack)->cie == tmp_max)
			tmp_max = pre_sort_a(a_stack, b_stack, tmp_max);
		else if ((*b_stack)->cie == n)
		{
			pre_list_push(b_stack, a_stack, 0);
			n--;
		}
		else
			list_rotate(a_stack, b_stack, 1);
	}
	*i_max = get_cie_max(*b_stack);
}

static void	return_to_a_from_the_bottom(t_list **a_stack,
										t_list **b_stack,
										int *i_max,
										int base)
{
	int	tmp_max;
	int	n;

	tmp_max = *i_max;
	n = *i_max - 1;
	while (*b_stack != NULL && (*b_stack)->prev->cie > (*i_max - base))
	{
		*b_stack = list_reverse_rotate(*b_stack, 1);
		if ((*b_stack)->cie == tmp_max)
			tmp_max = pre_sort_a(a_stack, b_stack, tmp_max);
		else if ((*b_stack)->cie == n)
		{
			pre_list_push(b_stack, a_stack, 0);
			n--;
		}
	}
	*i_max = get_cie_max(*b_stack);
}

static void	return_to_a_mod(t_list **a_stack,
							t_list **b_stack,
							int *i_max,
							int mod)
{
	int		cnt;

	cnt = 0;
	while (mod > cnt)
	{
		if ((*b_stack)->cie > (*b_stack)->prev->cie)
			return_to_a_from_the_top(a_stack, b_stack, i_max, mod);
		else
			return_to_a_from_the_bottom(a_stack, b_stack, i_max, mod);
		*i_max = get_cie_max(*b_stack);
		cnt = ft_lstsize(*a_stack);
		if (mod == cnt)
			break ;
	}
}

void	return_to_a(t_list **a_stack, t_list **b_stack, int i_max, int base)
{
	int	mod;

	mod = i_max % base;
	while (*b_stack != NULL)
	{
		if (mod != 0)
		{
			return_to_a_mod(a_stack, b_stack, &i_max, mod);
			mod = 0;
		}
		if ((*b_stack)->cie > (*b_stack)->prev->cie)
			return_to_a_from_the_top(a_stack, b_stack, &i_max, base);
		else
			return_to_a_from_the_bottom(a_stack, b_stack, &i_max, base);
	}
}

t_list	*move_to_b(t_list **a_stack, t_list **b_stack, int base, int num)
{
	int	max;

	max = base * 2;
	while (max > 0)
	{
		if ((*a_stack)->cie <= num)
		{
			pre_list_push(a_stack, b_stack, 1);
			max--;
		}
		else if ((*a_stack)->cie <= (num + base))
		{
			pre_list_push(a_stack, b_stack, 1);
			optimization_rotate_b(a_stack, b_stack, base + num);
			max--;
		}
		else
			optimization_rotate_a(a_stack, b_stack, base + num);
		if (*a_stack == NULL)
			break ;
	}
	return (*a_stack);
}
