/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_my.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qabderus <qabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:47:35 by qabderus          #+#    #+#             */
/*   Updated: 2022/04/12 17:37:28 by qabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear_my(t_list **lst)
{
	t_list	*tmp;
	t_list	*element;

	element = *lst;
	tmp = NULL;
	if (!lst || !*lst)
		return ;
	while (element)
	{
		if (element->next)
			tmp = element->next;
		else
			tmp = NULL;
		if (element->content != 0)
			element->content = 0;
		free(element);
		element = tmp;
	}
	*lst = NULL;
}
