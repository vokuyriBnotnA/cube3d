/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qabderus <qabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:47:35 by qabderus          #+#    #+#             */
/*   Updated: 2022/04/12 17:37:28 by qabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr_fd(char *str, int n, int fd)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		while (str[i] && i < (int)ft_strlen(str) + n)
		{
			ft_putchar_fd(str[i], fd);
			i++;
		}
	}
	else
	{
		while (str[i] && i < n)
		{
			ft_putchar_fd(str[i], fd);
			i++;
		}
	}		
}
