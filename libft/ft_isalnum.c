/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguadalu <mguadalu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:11:26 by mguadalu          #+#    #+#             */
/*   Updated: 2021/05/10 18:19:50 by mguadalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int cx)
{
	if ((cx >= 'A' && cx <= 'Z') || (cx >= 'a' && cx <= 'z') \
						|| (cx >= '0' && cx <= '9'))
		return (1);
	return (0);
}
