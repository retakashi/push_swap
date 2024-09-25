/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:34:26 by reira             #+#    #+#             */
/*   Updated: 2023/05/03 17:53:43 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	new_node_error(t_list **node, t_list *head)
{
	*node = head;
	return (-1);
}

static t_list	*new_node(int num)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->num = num;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

static int	get_node_argc2(char *argv, t_list **node)
{
	t_list	*new;
	t_list	*head;
	int		num;
	int		i;

	i = 0;
	i = get_number(argv, i, &num);
	*node = new_node(num);
	if (*node == NULL)
		return (-1);
	head = *node;
	while (argv[i] != '\0')
	{
		i = get_number(argv, i, &num);
		new = new_node(num);
		if (new == NULL)
			return (new_node_error(node, head));
		new->prev = *node;
		(*node)->next = new;
		*node = new;
	}
	head->prev = *node;
	(*node)->next = head;
	*node = head;
	return (0);
}

static int	get_node_argc_over2(int argc, char **argv, t_list **node)
{
	t_list	*new;
	t_list	*head;
	int		i;
	int		num;

	i = 1;
	num = ft_atoi_intver(argv[i++], 0);
	*node = new_node(num);
	if (*node == NULL)
		return (-1);
	head = *node;
	while (i < argc)
	{
		num = ft_atoi_intver(argv[i++], 0);
		new = new_node(num);
		if (new == NULL)
			return (new_node_error(node, head));
		new->prev = *node;
		(*node)->next = new;
		*node = new;
	}
	head->prev = *node;
	(*node)->next = head;
	*node = head;
	return (0);
}

int	get_node(int argc, char **argv, t_list **node)
{
	int	ret;

	ret = 0;
	if (argc == 2)
		ret = get_node_argc2(argv[1], node);
	else
		ret = get_node_argc_over2(argc, argv, node);
	return (ret);
}
