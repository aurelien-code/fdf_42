/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 07:06:57 by aumarin           #+#    #+#             */
/*   Updated: 2022/12/06 02:22:18 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_line;

t_line	init_line(int x0, int y0, int x1, int y1)
{
	t_line	t;

	t.dx = abs(x1 - x0);
	t.dy = -abs(y1 - y0);
	t.sx = -1;
	t.sy = -1;
	if (x0 < x1)
		t.sx = 1;
	if (y0 < y1)
		t.sy = 1;
	t.err = t.dx + t.dy;
	return (t);
}

void	bresenham(t_coordinates start, t_coordinates end, t_data win)
{
	t_line	t;

	t = init_line(start.x, start.y, end.x, end.y);
	while (1)
	{
		if (start.x < WIN_WIDTH && start.y < WIN_HEIGHT && start.x >= 0 \
			&& start.y >= 0)
			push_pixel(win, start.x, start.y, WHITE);
		if (start.x == end.x && start.y == end.y)
			break ;
		t.e2 = 2 * t.err;
		if (t.e2 >= t.dy)
		{
			t.err += t.dy;
			start.x += t.sx;
		}
		if (t.e2 <= t.dx)
		{
			t.err += t.dx;
			start.y += t.sy;
		}
	}
}
