/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qabderus <qabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:47:35 by qabderus          #+#    #+#             */
/*   Updated: 2022/04/12 17:37:28 by qabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int n)
{
	int		i;
	char	*buffer;

	i = -1;
	if (n < 0)
	{
		buffer = (char *)malloc(ft_strlen(s1) + 1 + n);
		if (buffer == NULL)
			return (0);
		while (s1[++i] && i < (int)ft_strlen(s1) + n)
			buffer[i] = s1[i];
	}
	else
	{
		buffer = (char *)malloc(n + 1);
		if (buffer == NULL)
			return (0);
		while (s1[++i] && i < n)
			buffer[i] = s1[i];
	}
	buffer[i] = '\0';
	return (buffer);
}
