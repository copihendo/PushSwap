#include "libft.h"

t_list	*ft_lstadd_front_content(t_list **list, void *content)
{
	t_list	*new;

	new = ft_lstnew(content);
	if (new)
		ft_lstadd_front(list, new);
	return (new);
}
