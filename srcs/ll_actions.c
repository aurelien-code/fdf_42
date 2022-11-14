/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:02:32 by aumarin           #+#    #+#             */
/*   Updated: 2022/11/09 18:12:52 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point *new_point(int x, int y, int z)
{
	t_point	*point;

	point = malloc(sizeof(t_point) * 1);
	if (!point)
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = z;
	point->x_pixel = -1;
	point->y_pixel = -1;
	point->next = NULL;
	return (point);
}

t_point	*add_last(t_map *map, t_point *point)
{
	t_point	*pt_head;

	if (!map || !point)
		return (NULL);
	if (!map->points)
	{
		map->points = point;
		return (point);
	}
	else
		pt_head = map->points;
	while (pt_head->next)
		pt_head = pt_head->next;
	pt_head->next = point;
	return (pt_head);
}

t_point	*get_point(int x, int y, t_point *head)
{
	if (!head || x < 0 || y < 0)
		return (NULL);
	while (head->next != NULL)
	{
		if (head->x == x && head->y == y)
			return (head);
		else
			head = head->next;
	}
	return (NULL);
}

t_point	*modify_point(int x, int y, t_point *head, t_point *new)
{
	t_point	*point_to_change;

	point_to_change = get_point(x, y, head);
	if (!point_to_change)
		return (NULL);
	else
	{
		new->next = point_to_change->next;
		point_to_change = new;
	}
	return (NULL);
}

void	free_points(t_map *map)
{
	t_point *point;
	t_point	*tmp;

	if (!map->points)
		return ;
	tmp = NULL;
	point = map->points;
	while (point->next)
	{
		if (tmp)
			free(tmp);
		tmp = point;
		point = point->next;
	}
	if (tmp)
		free(tmp);
	if (point)
		free(point);
}