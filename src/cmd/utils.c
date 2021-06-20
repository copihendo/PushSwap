#include "push_swap.h"

t_list	 *ft_pop_front(t_list **begin)
{
	t_list *res;

	if (!*begin)
		return(0);
	res = *begin; // разименовали ссылку(begin) на первый лист.
	*begin = res->next;
	res->next = NULL;
	return(res);   
}

t_list	*ft_pop_back(t_list **begin)
{
	t_list *previous;
	t_list *now;

	if(!*begin)
		return (0);
	previous = NULL;
	now = *begin;
	while (now->next)
	{
		previous = now;
		now = now->next;
	}
	if(previous)
		previous->next = NULL; // чтобы дальше не убежал, указываем на ноль, чтобы обрезать и забрать последний эдемент
	else
		*begin = 0;
	return(now);
}

