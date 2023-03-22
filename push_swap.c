/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reira <reira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:28:14 by reira             #+#    #+#             */
/*   Updated: 2023/03/22 23:14:09 by reira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
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

static int			ft_atoi(const char *str);
static size_t		check_space(const char *str, size_t i);
static size_t		check_sign(const char *str, size_t i, int *neg);
void get_coordinate(t_list *node);

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

// if==argc>2
t_list	*sort_argv(int argc, char *argv[])
{
	t_list	*node;
	t_list	*head;
	t_list	*new;
	t_list	*tail;
	int		i;

	i = 1;
	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->arr = calloc(sizeof(char), (ft_strlen(argv[i]) + 1));
	if (node->arr == NULL)
		return (NULL);
	strlcpy(node->arr, argv[i], ft_strlen(argv[i]) + 1);
	node->num = ft_atoi(node->arr);
    head = node;
	i++;
	while (argv[i]!=NULL)
	{
		new = malloc(sizeof(t_list));
		if (new == NULL)
			return (NULL);
		new->arr = calloc(sizeof(char), (ft_strlen(argv[i]) + 1));
		if (new->arr == NULL)
			return (NULL);
		strlcpy(new->arr, argv[i], ft_strlen(argv[i]) + 1);
		new->num = ft_atoi(new->arr);
		i++;
		if(node->num==new->num)
		return(NULL);
		else if (head->num > new->num)
		{
            head->prev = new;
            new->next = head;
			head = new;
            while(node->next!=NULL)
            node=node->next;
		}
		else if (node->num < new->num)
		{
			node->next = new;
			new->prev = node;
			node=new;
		}
		else
		{
			tail = node;
			while (node->num > new->num)
			{
				node=node->prev;
				if(node->num==new->num)
				return(NULL);
			}
			new->next = node->next;
			node->next = new;
			new->prev = node;
            node=node->next;
            node->prev=new;
			node = tail;
		}
        
	}
	get_coordinate(head);
	return (head);
}

void get_coordinate(t_list *node)
{
    int i;
    i=1;

    while(node->next!=NULL)
    {
		node->cie=i;
		i++;
		node=node->next;
    }
	node->cie=i;
}

static int	ft_atoi(const char *str)
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
		if ((neg == 0 && num > LONG_MAX / 10) || (neg == 0 && num == LONG_MAX
				/ 10 && (str[i] - '0') >= LONG_MAX % 10))
			return ((int)LONG_MAX);
		if ((neg == 1 && num > LONG_MIN / 10 * -1) || (neg == 1
				&& num == LONG_MIN / 10 * -1 && (str[i] - '0') >= LONG_MIN % 10
				* -1))
			return ((int)LONG_MIN);
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

t_list *ft_swap(t_list *a1,t_list *a2,t_list *senitinel)
{
 t_list *a2_next;
 
 a2_next=a2->next;
 a2->next=a1;
 a2_next->prev=a1;
 a1->next=a2_next;
 a1->prev=a2;
 a2->prev=senitinel;
 senitinel->next=a2;
 return(a2);
}

void ft_push(t_list *push,t_list *receive)
{   
    t_list *push_next;
	t_list *push_se;
	t_list *receive_se;

	push_se=push;
while(push_se->arr!=NULL)
push_se=push_se->next;
while(receive_se->arr!=NULL)
{
receive_se=receive_se->next;
}
    
    push_next=push->next;
    push_se->next=push_next;
    push_next->prev=push_se;
    receive->prev=push;
    push->next=receive;
    receive_se->next=push;
    push->prev->prev=receive_se;
    return;
}

t_list *set_sort(int argc,char *argv[] ,t_list *node)
{
	t_list *stock_a;
	t_list *sentinel;
	t_list *new;
	t_list *head;
	
	int i;
	
	i=1;
	stock_a=malloc(sizeof(t_list));
	if(stock_a==NULL)
	return(NULL);
	stock_a->arr=calloc(sizeof(char),ft_strlen(argv[i])+1);
		if(stock_a==NULL)
		return(NULL);
		strlcpy(stock_a->arr,argv[i],ft_strlen(argv[i])+1);
		stock_a->num=ft_atoi(stock_a->arr);
		stock_a->cie=0;
	head=stock_a;
	i++;
	while(i<argc)
	{
		new=malloc(sizeof(t_list));
	if(new==NULL)
	return(NULL);
		new->arr=calloc(sizeof(char),ft_strlen(argv[i])+1);
		if(new==NULL)
		return(NULL);
		strlcpy(new->arr,argv[i],ft_strlen(argv[i])+1);
		new->num=ft_atoi(new->arr);
		new->cie=0;
		stock_a->next=new;
		new->prev=stock_a;
		stock_a=new;
		i++;
	}
	new=malloc(sizeof(t_list));
	if(new==NULL)
	return(NULL);
		new->arr=NULL;
		new->num=0;
		new->cie=0;
		stock_a->next=new;
		new->prev=stock_a;
		new->next=head;
		head->prev=new;
	sentinel=new;
	head=ft_swap(head,head->next,sentinel);
	return(head);
}

int	main()
{
	t_list *ans;
	t_list *ans2;
	int i;
	i = 0;
    int argc=9;
    char *argv[10]={"a.out","123","456","75","100","-200","500","800","0"};
	char *argv2[10]={"a.out","789","456","75","100","-200","500","800","0"};

	// ans = sort_argv(argc, argv);
	// while (i < argc-1)
	// {
	// 	printf("anspoiter[%d] : %p\n", i, ans);
	// 	printf("ans[%d]->num: %d\n", i, ans->num);
	// 	printf("ans[%d]->arr: %s\n", i, ans->arr);
	// 	printf("ans[%d]->cie: %d\n", i, ans->cie);
	// 	printf("ans[%d]->next: %p\n", i, ans->next);
	// 	printf("ans[%d]->prev: %p\n", i, ans->prev);
	// 	i++;
	// 	ans = ans->next;
	// }
	// printf("\n");
	ans=set_sort(argc, argv,ans);
	ans2=set_sort(argc, argv2,ans2);

	ft_push(ans,ans2);
	i=0;
	while (ans->arr!=NULL)
	{
		printf("anspoiter[%d] : %p\n", i, ans);
		printf("ans[%d]->num: %d\n", i, ans->num);
		printf("ans[%d]->arr: %s\n", i, ans->arr);
		printf("ans[%d]->cie: %d\n", i, ans->cie);
		printf("ans[%d]->next: %p\n", i, ans->next);
		printf("ans[%d]->prev: %p\n", i, ans->prev);
		i++;
		ans = ans->next;
	}
	printf("anspoiter[%d] : %p\n", i, ans);
		printf("ans[%d]->num: %d\n", i, ans->num);
		printf("ans[%d]->arr: %s\n", i, ans->arr);
		printf("ans[%d]->cie: %d\n", i, ans->cie);
		printf("ans[%d]->next: %p\n", i, ans->next);
		printf("ans[%d]->prev: %p\n", i, ans->prev);
printf("\n");
i=0;
		while (ans2->arr!=NULL)
	{
		printf("anspoiter2[%d] : %p\n", i, ans2);
		printf("ans[%d]->num: %d\n", i, ans2->num);
		printf("ans[%d]->arr: %s\n", i, ans2->arr);
		printf("ans[%d]->cie: %d\n", i, ans2->cie);
		printf("ans[%d]->next: %p\n", i, ans2->next);
		printf("ans[%d]->prev: %p\n", i, ans2->prev);
		i++;
		ans2 = ans2->next;
	}
	printf("anspoiter[%d] : %p\n", i, ans2);
		printf("ans[%d]->num: %d\n", i, ans2->num);
		printf("ans[%d]->arr: %s\n", i, ans2->arr);
		printf("ans[%d]->cie: %d\n", i, ans2->cie);
		printf("ans[%d]->next: %p\n", i, ans2->next);
		printf("ans[%d]->prev: %p\n", i, ans2->prev);		
	return (0);
}