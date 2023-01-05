/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 03:16:59 by aumarin           #+#    #+#             */
/*   Updated: 2023/01/06 00:32:23 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	if (ft_min((WIN_WIDTH) / max_xx, WIN_HEIGHT / max_yy) > 2)
		return (ft_min((WIN_WIDTH) / max_xx, WIN_HEIGHT / max_yy) / 2);
	else
		return (ft_min((WIN_WIDTH) / max_xx, WIN_HEIGHT / max_yy));
}

int	*get_offset(t_map *map)
{
	t_point	*point;
	int		min_y;
	int		max_y;
	int		*min;

	point = map->points;
	min_y = 0;
	max_y = 0;
	min = ft_calloc(2, sizeof(int));
	if (!min)
		return (NULL);
	min[0] = 0;
	while (point)
	{
		if ((point->x - point->y) * map->zoom * cos(RAD_30) < min[0])
			min[0] = (point->x - point->y) * map->zoom;
		if ((((point->x + point->y) * map->zoom) / 2) * sin(RAD_30) < min_y)
			min_y = (((point->x + point->y) * map->zoom) / 2) * sin(RAD_30);
		if ((((point->x + point->y) * map->zoom) / 2) * sin(RAD_30) > max_y)
			max_y = (((point->x + point->y) * map->zoom) / 2) * sin(RAD_30);
		point = point->next;
	}
	min[0] = abs(min[0]);
	min[1] = abs(min_y) + (WIN_HEIGHT - max_y) / 2;
	return (min);
}

int	get_depth(t_map *map)
{
	t_point	*point;
	t_point	max_z;
	t_point	min_z;
	int		depth;

	depth = 1;
	point = map->points;
	max_z.z = 0;
	min_z.z = 0;
	while (point)
	{
		if (point->z > max_z.z)
			max_z = *point;
		if (point->z < min_z.z)
			min_z = *point;
		point = point->next;
	}
	if (min_z.z == 0 && max_z.z == 0)
		return (0);
	while ((((max_z.x + max_z.y) * map->zoom) / 2) * \
			sin(RAD_30) - (max_z.z * depth) + map->offset_y > 0)
		depth++;
	printf("Depth = %d | zoom = %d", depth - 1, get_zoom(map));
	if (get_zoom(map) / 2 > depth || get_zoom(map) == 1)
		return (depth - 1);
	else
		return (depth - get_zoom(map) / 2);
}

void	apply_scale(t_map *map)
{
	t_point	*point;
	int		xx;
	int		yy;
	int		*oset;

	point = map->points;
	map->zoom = get_zoom(map);
	oset = get_offset(map);
	map->offset_x = abs(oset[0]);
	map->offset_y = abs(oset[1]);
	map->depth = get_depth(map);
	while (point->next)
	{
		xx = ((point->x - point->y) * map->zoom);
		yy = ((point->x + point->y) * map->zoom) / 2;
		point->x_pixel = map->offset_x + (xx) * cos(RAD_30);
		point->y_pixel = map->offset_y + (yy) * sin(RAD_30) - \
			(point->z * map->depth);
		point = point->next;
	}
	free(oset);
	return ;
}
