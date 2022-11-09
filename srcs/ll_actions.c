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

/*
	@return the new point adress
*/
t_point	add_last(t_map *map, t_point *point)
{
	t_point	*pt_head;

	if (!map || !point)
		return (NULL);
	if (!map->points)
	{
		map->points = point;
		pt_head = point;
	}
	else
		pt_head = map->points;
	while (pt_head->next != NULL)
		pt_head = pt_head->next;
	pt_head->next = point;
	return (map);
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
