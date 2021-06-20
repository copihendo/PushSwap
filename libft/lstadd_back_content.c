#include "libft.h"

t_list	*ft_lstadd_back_content(t_list **list, void *content)
{
	t_list	*last;
	t_list	*new;

	new = ft_lstnew(content);
	if (new)
	{
		last = ft_lstlast(*list);
		if (!last)
			*list = new;
		else
			last->next = new;
	}
	return (new);
}
