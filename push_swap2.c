/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reira <reira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:34:26 by reira             #+#    #+#             */
/*   Updated: 2023/03/30 15:47:39 by reira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list
{
	char			*arr;
	int				num;
	int				cie;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

//push_swap流れ
//argv->atoi->int_arrに代入
//int_arrをmergesort->座標圧縮
//リスト構造にargvを代入
//int_arrのindex+1(座標圧縮)を二分探索でlst->cieに代入
//lstをクイックソート

//argv->atoi->int_arrに代入
//int_arrをmergesort->座標圧縮
//↓args_checkで出来そう！！
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

void	m_sort(int int_arr[], int left, int mid, int right, int sort[])
{
	int	i;
	int	j;
	int	k;
	int	size;

	i = left;
	j = mid + 1;
	k = 0;
	while (i <= mid && j <= right)
	{
        if(int_arr[i] == int_arr[j])
        int_arr[0]=-1;
		if (int_arr[i] < int_arr[j])
		{
			sort[k] = int_arr[i];
			k++;
			i++;
		}
		else
		{
			sort[k] = int_arr[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		sort[k] = int_arr[i];
		k++;
		i++;
	}
	while (j <= right)
	{
		sort[k] = int_arr[j];
		k++;
		j++;
	}
	size = right - left + 1;
	memcpy(&int_arr[left], sort, sizeof(int) * size);
}

void	partition(int int_arr[], int left, int right, int sort[])
{
	int	mid;
    
	if (left == right)
		return ;
	mid = (left + right) / 2;
	partition(int_arr,left, mid, sort);
	partition(int_arr,mid + 1, right, sort);
	m_sort(int_arr, left, mid, right, sort);
}

t_list	*set_node(int argc, char **argv)
{
	t_list	*node;
	t_list	*new;
	t_list	*head;
	int		i;
	int		len;

	i = 1;
	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	len = strlen(argv[i]) + 1;
	node->arr = malloc(sizeof(char) * len);
	if (node == NULL)
		return (NULL);
	strlcpy(node->arr, argv[i], len);
	node->num = atoi(node->arr);
	node->prev = NULL;
	node->next = NULL;
	head = node;
	i++;
	while (i <= argc)
	{
		len = strlen(argv[i]) + 1;
		new = malloc(sizeof(t_list));
		if (new == NULL)
			return (NULL);
		new->arr = malloc(sizeof(char) * len);
		if (new == NULL)
			return (NULL);
		strlcpy(new->arr, argv[i], len);
		new->num = atoi(new->arr);
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
            node->num=int_arr[mid];
			break ;
		}
		if (node->num < int_arr[mid])
			max = mid;
		else
			min = mid + 1;
	}
	return ;
}

void	q_sort(t_list *node)
{
	t_list	*a_stock;
	t_list	*b_stock;

	a_stock = node;
}
int	main(void)
{
	int		argc;
	char	*argv[7]={ "a.out", "1", "8", "3", "4", "5" };
	int		i;
	int		int_arr[8];
	int		sort[8];
	t_list	*node;
	t_list	*head;

	argc = 5;
	i = 1;
	change_int(int_arr, argv);
	//    while(i<=argc)
	//    {
	//    printf("%d\n",int_arr[i]);
	//    i++;
	//    }
	//    printf("\n");
	partition(int_arr, 1, argc, sort);
	i = 0;
	while (i <= argc)
	{
		printf("int[%d] %d\n", i, int_arr[i]);
		i++;
	}
	printf("\n");
	//    node=set_node(argv);
	//    head=node;
	//    i=1;
	//    while(i<=argc)
	//    {
	// set_cie(int_arr,node,1,argc);
	// node=node->next;
	// i++;
	//    }
	//    i=1;
	//    while(i<=argc)
	//    {
	//     printf("node[%d] %d\n",i,head->num);
	//     printf("node->cie[%d] %d\n",i,head->cie);
	//     head=head->next;
	//     i++;
	//    }
	//    printf("node[%d] %d\n",i,head->num);
	//    printf("node->cie[%d] %d\n",i,head->cie);
	return (0);
}
