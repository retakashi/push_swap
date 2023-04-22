/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:34:26 by reira             #+#    #+#             */
/*   Updated: 2023/04/20 23:02:19 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_number(char *argv, int i, int *num)
{
	int		j;
	char	str[13];

	j = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] == ' ' && argv[i + 1] != '\0')
			i++;
		if (argv[i] == '-' || argv[i] == '+')
			str[j++] = argv[i++];
		while (ft_isdigit(argv[i]))
		{
			str[j] = argv[i];
			i++;
			j++;
		}
		str[j] = '\0';
		if (argv[i] == ' ' && argv[i + 1] != '\0')
			break ;
	}
	*num = ft_atoi_intver(str);
	return (i);
}

static t_list	*new_node(int num)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->num = num;
	return (new);
}

static t_list	*get_node_argc2(char *argv)
{
	t_list	*node;
	t_list	*new;
	t_list	*head;
	int		num;
	int		i;

	i = 0;
	i = get_number(argv, i, &num);
	node = new_node(num);
	head = node;
	while (argv[i] != '\0')
	{
		i = get_number(argv, i, &num);
		new = new_node(num);
		if (new == NULL)
			return (ft_free(NULL, &head));
		new->prev = node;
		node->next = new;
		node = new;
	}
	head->prev = node;
	node->next = head;
	return (head);
}

static t_list	*get_node_argc_over2(int argc, char **argv)
{
	t_list	*node;
	t_list	*new;
	t_list	*head;
	int		i;
	int		num;

	i = 1;
	num = ft_atoi_intver(argv[i++]);
	node = new_node(num);
	head = node;
	while (i < argc)
	{
		num = ft_atoi_intver(argv[i++]);
		new = new_node(num);
		if (new == NULL)
			return (ft_free(NULL, &head));
		new->prev = node;
		node->next = new;
		node = new;
	}
	node->next = head;
	head->prev = node;
	return (head);
}

t_list	*get_node(int argc, char **argv)
{
	t_list	*head;

	if (argc == 2)
		head = get_node_argc2(argv[1]);
	else
		head = get_node_argc_over2(argc, argv);
	return (head);
}
