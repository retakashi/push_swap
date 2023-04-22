# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtakashi <rtakashi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 18:49:43 by rtakashi          #+#    #+#              #
#    Updated: 2023/04/20 21:27:08 by rtakashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = args_error_check.c get_cie.c list_size3_sort.c main.c \
ft_atoi_intver.c get_int_arr.c list_size_over6.c merge_sort_int_arr.c \
ft_isdigit.c get_list.c list_size_over6_utils.c push_swap.c \
ft_lstsize.c list_push.c list_size_under6.c push_swap_utils.c \
	
OBJS = $(SRCS:.c=.o)
# BONUS_OBJS = $(BONUS_SRCS:.c=.o)
# ifdef WITH_BONUS
# OBJS += $(BONUS_OBJS)
# endif
# AR = ar
# ARFLAGS = rcs
RM = rm -f

.DEFAULT_GOAL :=$(NAME)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean: 
	$(RM) $(OBJS) 
# $(BONUS_OBJS)


fclean: clean
	$(RM) $(NAME)

re: fclean all

# bonus: 
# 	@make WITH_BONUS=1	

.PHONY: all clean fclean re
