/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 03:16:59 by aumarin           #+#    #+#             */
/*   Updated: 2022/12/06 12:37:10 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/** FORMULAS
 * 	xx = ((x - y) * map->zoom);
 * 	yy = ((x + y) * map->zoom) / 2;
 *	point->x_pixel = (WIN_WIDTH / 2) + (xx) * cos(RAD_45);
 *	point->y_pixel = (WIN_HEIGHT / 2) + (yy) * sin(RAD_45) - (z * map->depth);
*/

int	get_zoom(t_map *map)
{
	t_point	*point;
	int		xx;
	int		yy;
	int		max_xx;
	int		max_yy;

	max_xx = 0;
	max_yy = 0;
	point = map->points;
	while (point->next)
	{
		xx = abs((point->x - point->y));
		yy = abs((point->x + point->y)) / 2;
		if (xx > max_xx)
			max_xx = xx;
		if (yy > max_yy)
			max_yy = yy;
		point = point->next;
	}
	return (ft_min((WIN_WIDTH - 1 )/ max_xx, WIN_HEIGHT / max_yy) - 1);
}

int	get_depth(t_map *map)
{
	return (map->zoom);
}

int	get_offset(void)
{
	return (0);
}

void	apply_scale(t_map *map)
{
	t_point	*point;
	int		xx;
	int		yy;

	point = map->points;
	map->zoom = get_zoom(map);
	map->depth = get_depth(map);
	printf("ZOOOOM = %d\n", map->zoom);
	while (point->next)
	{
		xx = ((point->x - point->y) * map->zoom);
		yy = ((point->x + point->y) * map->zoom) / 2;
		point->x_pixel = (WIN_WIDTH / 3) + (xx) * cos(RAD_45);
		point->y_pixel = (WIN_HEIGHT / 3) + (yy) * sin(RAD_45) - \
			(point->z * map->depth);
		point = point->next;
	}
	return ;
}
