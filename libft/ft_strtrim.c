/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copihendo <copihendo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:02:48 by mguadalu          #+#    #+#             */
/*   Updated: 2021/06/17 16:36:44 by copihendo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*arr;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	end = ft_strlen(s1);
	while (end && s1[end - 1] && ft_strchr(set, s1[end - 1]))
		end--;
	arr = ft_substr((char *)s1, 0, end);
	return (arr);
}
