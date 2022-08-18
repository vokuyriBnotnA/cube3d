/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qabderus <qabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:47:35 by qabderus          #+#    #+#             */
/*   Updated: 2022/04/12 17:37:28 by qabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinch(char *str, char ch)
{
	char	*new_str;
	size_t	i;

	if (!str || !ch)
		return (NULL);
	new_str = (char *)malloc(sizeof(new_str) * (ft_strlen(str) + 2));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < ft_strlen(str))
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = ch;
	i++;
	new_str[i] = '\0';
	return (new_str);
}
