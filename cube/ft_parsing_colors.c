/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qabderus <qabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:47:35 by qabderus          #+#    #+#             */
/*   Updated: 2022/04/12 17:37:28 by qabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_check_two_color(t_map *map)
{
	if (map->ceil_color == -1 || map->ceil_color == -1)
		ft_putendl_error("Color is missing");
}

static int	ft_natoi(const char *str, int len)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < len)
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

static int	ft_color_range(char *str, int *i, int *comma)
{
	int	j;
	int	temp;

	while (str[*i] == ' ' || str[*i] == '\t')
		(*i)++;
	if (ft_isdigit(str[*i]) == 0 \
	|| (str[*i] == '0' && ft_isdigit(str[*i + 1]) == 1))
		ft_putendl_error("Color has invalid value");
	j = *i;
	while (ft_isdigit(str[*i]) == 1)
		(*i)++;
	temp = ft_natoi(str + j, *i - j);
	if (*i - j > 3 || temp < 0 || temp > 255)
		ft_putendl_error("Color has too few or too many value");
	if (str[*i] == ',')
	{
		(*comma)++;
		(*i)++;
	}
	return (temp);
}

static int	ft_color_converting(char *str)
{
	int	i;
	int	comma;
	int	temp;
	int	count;
	int	res;

	i = 0;
	comma = 0;
	temp = 0;
	count = 0;
	res = 0;
	while (str[i] != '\0')
	{
		temp = ft_color_range(str, &i, &comma);
		count++;
		res = (res << 8) + temp;
		temp = 0;
	}
	if (count != 3)
		ft_putendl_error("Color has too few or too many numbers");
	if (comma != 2)
		ft_putendl_error("Color has too few or too many comma");
	return (res);
}

int	ft_parsing_colors(t_map *map, char *line)
{
	if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
	{
		if (ft_strncmp(line, "F ", 2) == 0)
		{
			if (map->floor_color != -1)
				ft_putendl_error("Floor color is existing already");
			map->floor_color = ft_color_converting(line + 2);
		}
		else
		{
			if (map->ceil_color != -1)
				ft_putendl_error("Ceilling color is existing already");
			map->ceil_color = ft_color_converting(line + 2);
		}
		return (1);
	}
	return (0);
}
