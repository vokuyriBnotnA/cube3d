/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qabderus <qabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:47:35 by qabderus          #+#    #+#             */
/*   Updated: 2022/04/12 17:37:28 by qabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char *str, char *replace_what, char *replace_by)
{
	char	*new_path;
	int		done;
	int		i;
	char	*tmp;

	if (!ft_strnstr(str, replace_what, ft_strlen(str)))
		return (NULL);
	new_path = ft_strdup("");
	done = 0;
	i = -1;
	while (str[++i])
	{
		tmp = new_path;
		if (ft_strncmp(str + i, replace_what, ft_strlen(replace_what)) == 0 \
		&& !done)
		{
			new_path = ft_strjoin(new_path, replace_by);
			i += ft_strlen(replace_what) - 1;
			done = 1;
		}
		else
			new_path = ft_strjoinch(new_path, str[i]);
		free(tmp);
	}
	return (new_path);
}
