#include "push_swap.h"

void ft_swap_a(t_base *base, char flag)
{
	t_list *lst_first;
	t_list *lst_second;

	if (!(base->stack_A && base->stack_A->next))
		return ;
	lst_first = ft_pop_front(&base->stack_A);
	lst_second = ft_pop_front(&base->stack_A);
	ft_lstadd_front(&base->stack_A, lst_first);
	ft_lstadd_front(&base->stack_A, lst_second);
	if (flag)
		write(1, "sa\n", 3);

}

void ft_swap_b(t_base *base, char flag)
{
	t_list *lst_first;
	t_list *lst_second;

	if (!(base->stack_B && base->stack_B->next))
		return ;
	lst_first = ft_pop_front(&base->stack_B);
	lst_second = ft_pop_front(&base->stack_B);
	ft_lstadd_front(&base->stack_B, lst_first);
	ft_lstadd_front(&base->stack_B, lst_second);
	if (flag)
		write(1, "sb\n", 3);
}

void ft_swap_ab(t_base *base, char flag)
{
	char exist_A;
	char exist_B;

	exist_A = (base->stack_A && base->stack_A->next);
	exist_B = (base->stack_B && base->stack_B->next);
	ft_swap_a(base, flag && !(exist_A && exist_B));
	ft_swap_b(base, flag && !(exist_A && exist_B));
	if (exist_A && exist_B && flag)
		write(1, "ss\n", 3);
}