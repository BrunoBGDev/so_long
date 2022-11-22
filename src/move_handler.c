/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:51:51 by bbraga            #+#    #+#             */
/*   Updated: 2022/11/22 10:25:23 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	change_player_img(t_param *param, char c)
{
	mlx_clear_window(param->mlx, param->mlx_win);
	mlx_destroy_image(param->mlx, param->player);
	if (c == 'u')
		put_image(param, &param->player, "./sprites/player/char_down.xpm");
	if (c == 'r')
		put_image(param, &param->player, "./sprites/player/char_right.xpm");
	if (c == 'l')
		put_image(param, &param->player, "./sprites/player/char_left.xpm");
	if (c == 'd')
		put_image(param, &param->player, "./sprites/player/char_front.xpm");
}

int	move_up(t_param *param)
{
	int	x;
	int	y;

	param->player_y--;
	x = param->player_x;
	y = param->player_y;
	change_player_img(param, 'u');
	if (param->map[y][x] == '0' || param->map[y][x] == 'C')
	{
		if (param->map[y][x] == 'C')
			param->c--;
		param->map[y][x] = 'P';
		param->map[y + 1][x] = '0';
		init_map(param);
		return (1);
	}
	if (param->map[y][x] == 'E' && param->c == 0)
	{
		param->map[y + 1][x] = '0';
		param->success = 1;
		free_all_exit(param);
	}
	param->player_y++;
	init_map(param);
	return (0);
}

int	move_down(t_param *param)
{
	int	x;
	int	y;

	param->player_y++;
	x = param->player_x;
	y = param->player_y;
	change_player_img(param, 'd');
	if (param->map[y][x] == '0' || param->map[y][x] == 'C')
	{
		if (param->map[y][x] == 'C')
			param->c--;
		param->map[y][x] = 'P';
		param->map[y - 1][x] = '0';
		init_map(param);
		return (1);
	}
	if (param->map[y][x] == 'E' && param->c == 0)
	{
		param->map[y - 1][x] = '0';
		param->success = 1;
		free_all_exit(param);
	}
	param->player_y--;
	init_map(param);
	return (0);
}

int	move_left(t_param *param)
{
	int	x;
	int	y;

	param->player_x--;
	x = param->player_x;
	y = param->player_y;
	change_player_img(param, 'l');
	if (param->map[y][x] == '0' || param->map[y][x] == 'C')
	{
		if (param->map[y][x] == 'C')
			param->c--;
		param->map[y][x] = 'P';
		param->map[y][x + 1] = '0';
		init_map(param);
		return (1);
	}
	if (param->map[y][x] == 'E' && param->c == 0)
	{
		param->map[y][x + 1] = '0';
		param->success = 1;
		free_all_exit(param);
	}
	param->player_x++;
	init_map(param);
	return (0);
}

int	move_right(t_param *param)
{
	int	x;
	int	y;

	param->player_x++;
	x = param->player_x;
	y = param->player_y;
	change_player_img(param, 'r');
	if (param->map[y][x] == '0' || param->map[y][x] == 'C')
	{
		if (param->map[y][x] == 'C')
			param->c--;
		param->map[y][x] = 'P';
		param->map[y][x - 1] = '0';
		init_map(param);
		return (1);
	}
	if (param->map[y][x] == 'E' && param->c == 0)
	{
		param->map[y][x - 1] = '0';
		param->success = 1;
		free_all_exit(param);
	}
	param->player_x--;
	init_map(param);
	return (0);
}
