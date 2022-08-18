/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qabderus <qabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:47:35 by qabderus          #+#    #+#             */
/*   Updated: 2022/04/12 17:37:28 by qabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;
	int	length;

	i = 0;
	j = 0;
	if (needle[j] == ' ' || needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && len != 0)
	{
		length = len;
		while (haystack[i + j] != '\0' && len != 0 \
				&& haystack[i + j] == needle[j])
		{
			j++;
			len--;
			if (needle[j] == '\0')
				return ((char *)haystack + i);
		}
		j = 0;
		i++;
		len = length;
		len--;
	}
	return ((void *)0);
}
