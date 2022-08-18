/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qabderus <qabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:47:35 by qabderus          #+#    #+#             */
/*   Updated: 2022/04/12 17:37:28 by qabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *buffer, size_t new_size)
{
	char	*new_buffer;
	size_t	old_size;

	if (buffer == 0)
		return (malloc(new_size));
	old_size = sizeof(buffer);
	if (new_size <= old_size)
		return (buffer);
	new_buffer = malloc(new_size);
	ft_memcpy(new_buffer, buffer, old_size);
	free(buffer);
	return (new_buffer);
}
