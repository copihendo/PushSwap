/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copihendo <copihendo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:45:14 by mguadalu          #+#    #+#             */
/*   Updated: 2021/06/17 16:35:47 by copihendo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*updst;
	unsigned char	*upsrc;
	size_t			i;

	updst = (unsigned char *)dst;
	upsrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		updst[i] = upsrc[i];
		if (upsrc[i] == (unsigned char)c)
			return ((void *)(dst+ i + 1));
		i++;
	}
	return (NULL);
}
