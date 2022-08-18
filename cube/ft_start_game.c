/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qabderus <qabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:47:35 by qabderus          #+#    #+#             */
/*   Updated: 2022/04/12 17:37:28 by qabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_program_close(void)
{
	ft_putendl_fd("Exit the game", 1);
	exit(EXIT_SUCCESS);
}

static void	ft_init_mlx(t_map *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
}

static int	ft_drawer(t_data *data)
{
	ft_init_backimg(data);
	ft_draw_corf(data, 0, WIN_HEIGHT / 2, data->map->ceil_color);
	ft_draw_corf(data, WIN_HEIGHT / 2, WIN_HEIGHT, data->map->floor_color);
	ft_main_loop(data);
	mlx_put_image_to_window(\
	data->map->mlx, data->map->win, data->img.img_ptr, 0, 0);
	mlx_destroy_image(data->map->mlx, data->img.img_ptr);
	return (0);
}

static void	ft_move(t_data *data)
{
	mlx_hook(data->map->win, 2, 0, ft_key_press, data);
	mlx_hook(data->map->win, 17, 0, ft_program_close, NULL);
	mlx_loop_hook(data->map->mlx, ft_drawer, data);
	mlx_loop(data->map->mlx);
}

int	ft_start_game(t_data *data)
{
	ft_init_mlx(data->map);
	ft_init_ray(data);
	ft_init_textures(data->map);
	ft_drawer(data);
	ft_move(data);
	return (0);
}
