/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:40:57 by bbraga            #+#    #+#             */
/*   Updated: 2022/11/22 11:06:42 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_param	*init_param(t_param *param)
{
	param->player_x = 0;
	param->player_y = 0;
	param->map = NULL;
	param->width = 0;
	param->height = 0;
	param->mlx = NULL;
	param->mlx_win = NULL;
	param->mlx_img = NULL;
	param->count = 0;
	param->c = 0;
	param->e = 0;
	param->p = 0;
	param->player = NULL;
	param->wall = NULL;
	param->enemie = NULL;
	param->grass = NULL;
	param->chest = NULL;
	param->success = 0;
	param->fail = 0;
	return (param);
}

static int	check_file(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] && argv[i] != '.')
		i++;
	if (ft_strncmp((argv + i), ".ber", 4) != 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_param	*param;

	if (argc != 2)
		exit_error("ERROR! FORMAT: ./so_long <MAP.BER>", 0);
	if (!check_file(argv[1]))
		exit_error("File is not .ber", 0);
	param = (t_param *)malloc(sizeof(t_param));
	param = init_param(param);
	build_map(argv[1], param);
	game(param);
	return (0);
}
