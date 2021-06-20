#include "push_swap.h"

void	ft_push_a(t_base *base, char flag)
{
	if (!base->stack_B)
		return ;
	ft_lstadd_front(&base->stack_A, ft_pop_front(&base->stack_B));
	if (flag)
		write(1, "pa\n", 3);
}


void	ft_push_b(t_base *base, char flag)
{
	if (!base->stack_A)
		return ;	
	ft_lstadd_front(&base->stack_B, ft_pop_front(&base->stack_A));
	if (flag)
		write(1, "pb\n", 3);
}
