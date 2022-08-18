/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qabderus <qabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:47:35 by qabderus          #+#    #+#             */
/*   Updated: 2022/04/12 17:37:28 by qabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_putendl_error(char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

static void	ft_free(t_data *data)
{
	int	i;

	i = 0;
	while (data->map->array[i] != NULL)
	{
		free(data->map->array[i]);
		i++;
	}
	free(data->map->array);
	free(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		ft_putendl_error("You should enter 1 map");
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		ft_putendl_error("Map: Malloc error");
	data->map = (t_map *)malloc(sizeof(t_map));
	if (data->map == NULL)
		ft_putendl_error("Info: Malloc error");
	data->player = (t_player *)malloc(sizeof(t_player));
	if (data->player == NULL)
		ft_putendl_error("Player: Malloc error");
	ft_parsing_map(data, argv[1]);
	ft_start_game(data);
	ft_free(data);
	return (0);
}
