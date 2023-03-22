/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reira <reira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:24:46 by reira             #+#    #+#             */
/*   Updated: 2023/03/22 22:47:31 by reira            ###   ########.fr       */
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

// se = senitinel
t_list *ft_push(t_list *push,t_list *push_se,t_list *receive,t_list *receive_se)
{   
    t_list *push_next;
    
    push_next=push->next;
    push_se->next=push_next;
    push_next->prev=push_se;
    receive->prev=push;
    push->next=receive;
    receive_se->next=push;
    push->prev->prev=receive_se;
    return(push);
}

void ft_rotate()
{
    
}

void ft_reverse_rotate()
{
    
}
