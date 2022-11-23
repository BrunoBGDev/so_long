/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_mac.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:56:38 by bbraga            #+#    #+#             */
/*   Updated: 2022/11/23 13:52:43 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_window(t_param *param)
{
	int	height;
	int	width;

	height = (param->height + 1) * 64;
	width = param->width * 64;
	param->mlx = mlx_init();
	param->mlx_win = mlx_new_window(param->mlx, width, height, "so_long");
	param->mlx_img = mlx_new_image(param->mlx, width, height);
	if (param->mlx == 0 || param->mlx_win == 0 || param->mlx_img == 0)
	{
		free_all(param);
		exit_error("ERROR: FAILED TO INITIALIZE", 0);
	}
}

static void	init_images(t_param *param)
{
	put_image(param, &param->player, "./sprites/player/char_front.xpm");
	put_image(param, &param->portal, "./sprites/map_images/Portal.xpm");
	put_image(param, &param->chest, "./sprites/map_images/Chest.xpm");
	put_image(param, &param->wall, "./sprites/map_images/Trees.xpm");
	put_image(param, &param->grass, "./sprites/map_images/Grass.xpm");
}

static void	init_item(t_param *param, void *item, int i, int j)
{
	if (item == param->player)
	{
		param->player_x = i;
		param->player_y = j;
		mlx_put_image_to_window(param->mlx, param->mlx_win, \
			item, i * 64, j * 64);
	}
	else
		mlx_put_image_to_window(param->mlx, param->mlx_win, \
			item, i * 64, j * 64);
}

int	init_map(t_param *param)
{
	int	i;
	int	j;

	j = -1;
	while (param->map[++j])
	{
		i = -1;
		while (param->map[j][++i])
		{
			if (param->map[j][i] == 'E')
				init_item(param, param->portal, i, j);
			if (param->map[j][i] == '1')
				init_item(param, param->wall, i, j);
			if (param->map[j][i] == 'C')
				init_item(param, param->chest, i, j);
			if (param->map[j][i] == 'P')
				init_item(param, param->player, i, j);
			if (param->map[j][i] == '0')
				init_item(param, param->grass, i, j);
		}
	}
	return (0);
}

void	game(t_param *param)
{
	init_window(param);
	init_images(param);
	init_map(param);
	mlx_hook(param->mlx_win, 2, 1L << 0, movement_count, param);
	mlx_hook(param->mlx_win, 17, 1L << 17, free_all_exit, param);
	mlx_hook(param->mlx_win, 9, 1L << 21, init_map, param);
	mlx_loop(param->mlx);
}
