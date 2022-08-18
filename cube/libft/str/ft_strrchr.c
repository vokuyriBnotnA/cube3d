/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qabderus <qabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:47:35 by qabderus          #+#    #+#             */
/*   Updated: 2022/04/12 17:37:28 by qabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char	*k;
	char		ch;

	k = (char *)s;
	ch = (char)c;
	while (*s != '\0')
	{
		if (*s == ch)
			k = s;
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	s = k;
	if (*s == ch)
		return ((char *)s);
	return ((void *)0);
}
