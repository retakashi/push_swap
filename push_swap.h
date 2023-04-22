/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:36:12 by rtakashi          #+#    #+#             */
/*   Updated: 2023/04/20 23:28:21 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				num;
	int				cie;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

//args_error_check.c
int					args_error_check(int argc, char **argv);

//Libft
int					ft_isdigit(int c);
int					ft_lstsize(t_list *node);
int					ft_atoi_intver(const char *str);

//get_cie.c
void				binary_search_cie(int *int_arr, t_list *node, int min,
						int *max);

//get_int_arr.c
int					*get_int_arr(int argc, char **argv, int *int_arr,
						int *i_max);
//get_list.c
int					get_number(char *argv, int i, int *num);
t_list				*get_node(int argc, char **argv);

//list_push.c
void				pre_list_push(t_list **push, t_list **receive, int flg);

//list_size_over6_utils.c
int					get_cie_max(t_list *stack);
void				optimization_rotate_a(t_list **a_stack, t_list **b_stack,
						int max);
void				optimization_rotate_b(t_list **a_stack, t_list **b_stack,
						int max);
int					pre_sort_a(t_list **a_stack, t_list **b_stack, int tmp_max);

//list_size_over6.c
void				return_to_a(t_list **a_stack, t_list **b_stack, int i_max,
						int base);
t_list				*move_to_b(t_list **a_stack, t_list **b_stack, int base,
						int num);

//list_size_under6.c
t_list				*sort_size2(t_list *head, int flg);
t_list				*sort_size3(t_list *node, int flg);
t_list				*sort_size_4to6(t_list *a_stack, int i_max);

//list_size3_sort.c
t_list				*sort_list_ascending(t_list *head, int max, int arr[],
						int flg);
t_list				*sort_list_descending(t_list *head, int max, int arr[],
						int flg);

//main.c
void				put_operations(char *str);
void				*ft_free(int *arr, t_list **stack);

//merge_sort_int_arr.c
int					sort_ascending_and_arror_check(int *arr, int i_max);
void				m_sort_partition(int *int_arr, int left, int right);

//push_swap_utils.c
void				list_swap(t_list *a, t_list *b, int flg);
void				list_rotate(t_list **a_stack, t_list **b_stack, int flg);
t_list				*list_reverse_rotate(t_list *stack, int flg);

//push_swap.c
void				push_swap(t_list *a_stack, int i_max);

#endif