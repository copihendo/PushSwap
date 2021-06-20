#include "push_swap.h"

void	ft_lstadd_sort(t_list **ptr, t_list *new, int (*ft_compare)(void*, void *))
{
	t_list *now;
	t_list *previous;

	previous = NULL;
	now = *ptr;
	while (now)
	{
		if (ft_compare(now->content, new->content) > 0)
			break;
		previous = now;
		now = now->next;
	}
	if (previous)
		previous->next = new; 
	else 
		*ptr = new;
	new->next = now;
}

t_list *ft_lst_sort_content(t_list **ptr, void *content, int (*ft_compare)(void*, void *))
{
	t_list *new;
	
	new = ft_lstnew(content);
	if (new)
		ft_lstadd_sort(ptr, new, ft_compare);
	return (new);
}

int	ft_lst_compare(void *left_cont, void *right_cont)
{
	return (((t_number*)left_cont)->value - ((t_number*)right_cont)->value);
}

void	ft_indexation(t_base *base)
{	
	t_list *sort;
	t_list *ptr;
	int i;
	t_list *ptr_sort;


	sort = NULL;
	ptr = base->stack_A;

	while (ptr)
	{
		ft_lst_sort_content(&sort, ptr->content, ft_lst_compare);
		ptr = ptr->next;
	}
	i = 1;
	ptr_sort = sort;
	while (ptr_sort)
	{
		((t_number *)ptr_sort->content)->value = i;
		ptr_sort = ptr_sort->next;
		i++;
	}
	ft_lstclear(&sort, 0);
}

t_number *ft_create_number(const char *argv, t_group *group)
{
	t_number *number;

	number = ft_calloc(1, sizeof(t_number));
	if(!number)
		return(0);
	number->value = ft_atoi(argv);
	number->group = group;
	return(number);
}


void	ft_init_stackA(t_base *base, int argc, const char *argv[])
{
	int i;
	t_group *group;
	t_number *number;

	group = ft_group_create(base, 1, argc - 1);
	i = 1;
	while (i < argc)
	{
		number = ft_create_number(argv[i], group);
		ft_lstadd_back_content(&base->stack_A, number);
		i++;
	}	
}

void ft_pr_n(t_number *num)
{
	printf("%d\n", num->value);
}

int main(int argc, const char *argv[])
{
	t_base base;

	ft_bzero(&base, sizeof(t_base));
	ft_init_stackA(&base, argc, argv);
	ft_indexation(&base);
	// ft_lstiter(base.stack_A, (void (*)(void *))ft_pr_n);
	// ft_lstiter(base.stack_B, (void (*)(void *))ft_pr_n);
	// ft_swap_ab(&base, 1);
	// ft_lstiter(base.stack_A, (void (*)(void *))ft_pr_n);
	// ft_lstiter(base.stack_B, (void (*)(void *))ft_pr_n);
	ft_general(&base);
}