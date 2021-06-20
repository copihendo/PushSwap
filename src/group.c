#include "push_swap.h"

void ft_group_set(t_group *group, int min, int max)
{
	group->min = min;
	group->max = max;
	if (max - min > 5)
		group->med = ((max - min) / 3) * 2 + min;
	else 
		group->med = (max - min) / 2 + min;
}

t_group *ft_group_create(t_base *base, int min, int max)
{
	t_group *group;

	group = ft_calloc(1, sizeof(t_group));
	ft_lstadd_front_content(&base->groups, group);
	if (!group)
		return (0);
	ft_group_set(group, min, max);
	return (group);
}
