/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:57:28 by aumarin           #+#    #+#             */
/*   Updated: 2022/11/23 11:42:14 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	push_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	plot_line(int x0, int y0, int x1, int y1, t_data *win)
{
	int	sx;
	int	sy;
	int	e2;

	sx = -1;
	sy = -1;
	if (x0 < x1)
		sx = 1;
	if (y0 < y1)
		sy = 1;
	if (abs(x1 - x0) > abs(y1 - y0))
		e2 = abs(x1 - x0) / 2;
	else
		e2 = -abs(y1 - y0) / 2;
	while (1)
	{
		push_pixel(win, x0, y0, BLUE);
		if (x0 == x1 && y0 == y1)
			break ;
		if (e2 > -abs(x1 - x0))
		{
			e2 -= abs(y1 - y0);
			x0 += sx;
		}
		if (e2 < abs(y1 - y0))
		{
			e2 += abs(x1 - x0);
			y0 += sy;
		}
	}
}

void	draw_line(t_point *origin, t_point *dest, t_data *win)
{
	int	starting_x;
	int	starting_y;
	int	end_x;
	int	end_y;

	starting_x = (WIN_WIDTH / 2) + (origin->x_pixel * SCALE);
	starting_y = (WIN_HEIGHT / 2) + (origin->y_pixel * SCALE);
	end_x = (WIN_WIDTH / 2) + (dest->x_pixel * SCALE);
	end_y = (WIN_HEIGHT / 2) + (dest->y_pixel) * SCALE;
	plot_line(starting_x, starting_y, end_x, end_y, win);
	printf("push_px : [%d, %d] ; [%d, %d]\n", starting_x, starting_y, end_x, end_y);
}

void	init_windows(t_map *map)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_point	*p;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	img.img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
								&img.line_length, &img.endian);
	p = map->points;
	while (p->next)
	{
		if (p->next)
			draw_line(p, p->next, &img);
		p = p->next;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 10, 10);
	mlx_loop(mlx);
}
