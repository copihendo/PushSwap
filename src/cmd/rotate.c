#include "push_swap.h"

void	ft_rotate_a(t_base *base, char flag)
{
	if(!(base->stack_A && base->stack_A->next))
		return ;
	ft_lstadd_back(&base->stack_A, ft_pop_front(&base->stack_A));
	if (flag)
		write(1, "ra\n", 3);
}

void ft_rotate_b(t_base *base, char flag)
{
	if (!(base->stack_B && base->stack_B->next))
		return ;
	ft_lstadd_back(&base->stack_B, ft_pop_front(&base->stack_B));
	if (flag)
		write(1, "rb\n", 3);
}

void ft_rotate_ab(t_base *base, char flag)
{
	char exist_A;
	char exist_B;

	exist_A = base->stack_A && base->stack_A->next;
	exist_B = base->stack_B && base->stack_B->next;
	ft_rotate_a(base, flag && !(exist_A && exist_B));
	ft_rotate_b(base, flag && !(exist_A && exist_B));	
	if (exist_A && exist_B && flag)
		write(1, "rr\n", 4);
}
