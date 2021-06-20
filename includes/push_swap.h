#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
#include <stdio.h>

typedef struct s_group
{
	int max;
	int min;
	int med;
}			t_group;

typedef struct s_number
{
		int value;
		t_group *group;
}		t_number;

typedef struct s_base
{
	t_list *groups;
	t_list *stack_A;
	t_list *stack_B;
	t_group group_B;
	t_group group_sort;
}				t_base;

void ft_general(t_base *base);

t_list	 *ft_pop_front(t_list **begin);
t_list	*ft_pop_back(t_list **begin);
void	ft_push_a(t_base *base, char flag);
void	ft_push_b(t_base *base, char flag);
void ft_rotate_a(t_base *base, char flag);
void ft_rotate_b(t_base *base, char flag);
void ft_rotate_ab(t_base *base, char flag);
void ft_swap_a(t_base *base, char flag);
void ft_swap_b(t_base *base, char flag);
void ft_swap_ab(t_base *base, char flag);
void ft_reverse_rotate_a(t_base *base, char flag);
void ft_reverse_rotate_b(t_base *base, char flag);
void ft_reverse_rotate_ab(t_base *base, char flag);
t_group *ft_group_create(t_base *base, int min, int max);
void ft_group_set(t_group *group, int min, int max);









#endif