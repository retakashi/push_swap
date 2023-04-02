/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:34:26 by reira             #+#    #+#             */
/*   Updated: 2023/04/02 21:57:02 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

typedef struct s_list
{
	char			*arr;
	int				num;
	int				cie;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

//↓args_checkで出来そう
void	change_int(int int_arr[], char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		int_arr[i] = atoi(argv[i]);
		i++;
	}
}

int	argv_words_count(char *argv)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] == '-' || (argv[i] >= '0' && argv[i] <= '9'
				&& argv[i] != '\0'))
			words++;
		while (argv[i] >= '0' && argv[i] <= '9' && argv[i] != '\0')
			i++;
		i++;
	}
	return (words);
}

int	argv_len_count(char *argv)
{
	int	cnt;

	cnt = 0;
	while (*argv == '-' || (*argv >= '0' && *argv <= '9' && *argv != '\0'))
	{
		cnt++;
		argv++;
	}
	return (cnt + 1);
}

char	**argc2_set_str2(char *argv)
{
	char	**str;
	int		i;
	int		words;
	int		len;

	words = argv_words_count(argv);
	str = malloc(sizeof(char *) * (words + 1));
	if (str == NULL)
		return (NULL);
	str[words] = NULL;
	i = 0;
	while (i < words)
	{
		len = argv_len_count(argv);
		argv += len;
		str[i] = malloc(sizeof(char) * (len));
		if (str[i] == NULL)
			return (NULL);
		strlcpy(str[i], argv - len, len);
		i++;
	}
	return (str);
}

t_list	*new_node(char *str)
{
	t_list	*new;
	int		len;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	len = strlen(str) + 1;
	new->arr = malloc(sizeof(char) * len);
	if (new == NULL)
		return (NULL);
	strlcpy(new->arr, str, len);
	new->num = atoi(new->arr);
	return (new);
}

t_list	*set_node(int argc, char **argv)
{
	t_list	*node;
	t_list	*new;
	t_list	*head;
	char	*str;
	int		i;

	i = 1;
	argc2_set_str(str, *argv, i);
		node = new_node(argv[i]);
	head = node;
	i++;
	while (i <= argc)
	{
		new = new_node(argv[i]);
		node->next = new;
		new->prev = node;
		node = new;
		i++;
	}
	return (head);
}

//int_arrのindex+1(座標圧縮)を二分探索でlst->cieに代入
void	set_cie(int int_arr[], t_list *node, int min, int max)
{
	int	mid;

	while (min <= max)
	{
		mid = (min + max) / 2;
		if (node->num == int_arr[mid])
		{
			node->cie = mid;
			node->num = int_arr[mid];
			break ;
		}
		if (node->num < int_arr[mid])
			max = mid;
		else
			min = mid + 1;
	}
}

int	main()
{
	char	*str[10]= {"1230", "456", "789","0"};
	char	**str2;
	int		i;

	i = 0;
	str2 = argc2_set_str2(str[0]);
	while (i < 4)
	{
		printf("str[%d] : %s\n", i, str2[i]);
		i++;
	}
	return (0);
}
