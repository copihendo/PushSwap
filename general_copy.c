#include "push_swap.h"

void ft_after_rotate(t_base *base, int count_rot)
{
	int		size_stack_A;
	void	(*ft_rot)(t_base *, char);

	size_stack_A = ft_lstsize(base->stack_A);
	ft_rot = ft_reverse_rotate_a;
	if (size_stack_A - count_rot < count_rot)
	{
		count_rot = size_stack_A - count_rot;
		ft_rot = ft_rotate_a;
	}	
	while(count_rot--)
		ft_rot(base, 1);
}

void	ft_trans_to_b(t_base *base)
{
	t_group *group_A;
	t_number *number_A;
	int i;
	int count_rra;
	
	i = 0;
	count_rra = 0;
	group_A = ((t_number *)base->stack_A->content)->group;
	while(base->stack_A && (i < group_A->max - group_A->min + 1))
	{
		number_A = base->stack_A->content;
		if (group_A != number_A->group)
			break;
		if ((number_A->value == base->group_sort.max + 1) && ((t_number *)ft_lstlast(base->stack_A)->content)->group == &base->group_sort)
		{
			ft_rotate_a(base, 1);
			base->group_sort.max++;
			number_A->group = &base->group_sort;
			group_A->min++;
			continue ;
		}
		else if (number_A->value <= group_A->med)
		{
			ft_push_b(base, 1);
			number_A->group = &base->group_B;
		}
		else 
		{
			ft_rotate_a(base, 1);
			count_rra++;
		}
		i++;
	}
	ft_after_rotate(base, count_rra);
	ft_group_set(&base->group_B, group_A->min, group_A->med);
	ft_group_set(group_A, group_A->med + 1, group_A->max);
}

void	ft_trans_to_a(t_base *base)
{
	t_number *number_B;
	t_group *group_B;
	int i;
	t_group *group_new;
	
	i = 0;
	group_B = ((t_number *)base->stack_B->content)->group;
	group_new = ft_group_create(base, group_B->med, group_B->max);
	while (base->stack_B && (i < group_B->max - group_B->min + 1))
	{
		number_B = base->stack_B->content;
		if (number_B->value == base->group_sort.max + 1)
		{
			ft_push_a(base, 1);
			ft_rotate_a(base, 1);
			number_B->group = &base->group_sort;
			base->group_sort.max++;
			group_B->min++;
			continue ;
		}
		if (number_B->value >= group_B->med)
		{
			ft_push_a(base, 1);
			number_B->group = group_new;
		}
		else
			ft_rotate_b(base, 1);
		i++;
	}
	ft_group_set(group_new, group_B->med, group_B->max);
	ft_group_set(group_B, group_B->min , group_B->med - 1);
}

int ft_is_sort(t_base *base)
{
	if (base->stack_B)
		return(0);
	if (!base->stack_A || ((t_number *)base->stack_A->content)->group == &base->group_sort)
		return(1);
	return (0);
}

t_number	*ft_get_by_index(t_base *base, int index)
{
	int i;
	t_list *ptr;

	i = 0;
	ptr = base->stack_A;
	while (i != index && ptr)
	{
		ptr = ptr->next;
		i++;
	}
	if (!ptr)
		return (NULL);
	return (ptr->content);

}

int	ft_check_swap(t_base *base, int index1,int index2)
{
	int			size;
	t_number	*number1;
	t_number	*number2;

	number1 = ft_get_by_index(base, index1);
	number2 = ft_get_by_index(base, index2);
	size = ft_lstsize(base->stack_A);
	if (number1 && number2 && !(number1->value == size && number2->value == 1) && number1->value > number2->value)
		return(1);
	return (0);
}

ft_stack_is_sort(t_base *base)
{
	t_list *ptr;
	t_number *prev;
	t_number *now;

	ptr = base->stack_A;
	prev = 0;

	while(ptr)
	{
		now = ptr->content;
		if (prev && now->value > prev->value)
			return (0);
		ptr = ptr->next;
		prev = now;
	}
	return (1);
}

void	ft_small_sort(t_base *base)
{
	int size; 
	int count;
	int flag_ra;
	int flag_rra;

	size = ft_lstsize(base->stack_A);
	while(ft_stack_is_sort(base))
	{
		if (ft_check_swap(base, 0, 1))
			ft_swap_a(base, 1);
		else
		{
			count = 1;
			while (count * 2 < size)
			{
				flag_ra = ft_check_swap(base, count, count + 1);
				flag_rra = ft_check_swap(base, size - count - 1, size - count);
				count++;
			}
			if (flag_ra)
				ft_rotate_a(base, 1);
			else if (flag_rra)
				ft_reverse_rotate_a(base, 1);
			else 
				break;
		}
	}
}


void ft_general(t_base *base)
{
	int	size;

	size = ft_lstsize(base->stack_A);

	if (size <= 5)
		ft_small_sort(base);
	else
		while (!ft_is_sort(base))
		{
			ft_trans_to_b(base);
			while (base->stack_B)
			{
				ft_trans_to_a(base);
			}
		}
}