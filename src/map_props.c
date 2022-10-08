/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_props.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:48:41 by bbraga            #+#    #+#             */
/*   Updated: 2022/10/07 16:05:45 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_tile	get_tile(t_data *data, t_vtr v)
{
	int	gx;
	int	gy;

	gx = v.x / data->bsize;
	gy = v.y / data->bsize;
	return (data->map.tiles[gy][gx]);
}

int	is_ovelap_tile(t_vtr v1, t_vtr v2, int o1, int o2)
{
	int	ts;
	int	w1;
	int	w2;

	ts = TILE_SIZE;
	if (o1 == 0)
		o1 = ts / 8;
	if (o2 == 0)
		o2 = ts / 8;
	w1 = ts - o1;
	w2 = ts - o2;
	if (v1.x == v2.x && v1.y == v2.y)
		return (1);
	if ((v1.x + w1) < (v2.x + o2) || (v1.x + o1) > (v2.x + w2))
		return (0);
	if ((v1.y + w1) < (v2.y + o2) || (v1.y + o1) > (v2.y + w2))
		return (0);
	return (1);
}

t_tile	random_free_tile(t_data *data, int r, int t)
{
	t_tile	**tiles;
	t_tile	ft;
	int		gx;
	int		gy;

	tiles = data->map.tiles;
	gy = 0;
	while (gy < data->map.grid_y)
	{
		gx = 0;
		while (gx < data->map.grid_x)
		{
			if (tiles[gy][gx].type == '0' && --t < 0)
			{
				ft = tiles[gy][gx];
				if (data->frame % 60 < r)
					return (ft);
			}
			gx++;
		}
		gy++;
	}
	return (ft);
}
