/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:44:11 by rtakashi          #+#    #+#             */
/*   Updated: 2023/04/02 20:00:58 by rtakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{
    int v;
    int v2;
    int x;
    int x2;
    int N;
    int arr[10]={9,8,7,6,5,4,3,2,1,0};

    v=-11;
    v2=11;
    N=0;
    
    while(N<10)
    {
        x = (v >> N) & 1;
    printf("%d\n",x);
    N++;
    }
    N=0;
    printf("\n");
    while(N<6)
    {
        x2 = (v2 >> N) & 1;
    printf("%d\n",x2);
    N++;
    }
    
    return(0);
}