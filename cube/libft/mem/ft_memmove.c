/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qabderus <qabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:47:35 by qabderus          #+#    #+#             */
/*   Updated: 2022/04/12 17:37:28 by qabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	i = 0;
	if (dst == '\0' && src == '\0')
		return (((void *)0));
	if (dst < src)
	{
		while (len != 0)
		{	
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
			len--;
		}
	}
	else
	{
		i = len - 1;
		while (len != 0)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			len--;
			i--;
		}
	}
	return (dst);
}
