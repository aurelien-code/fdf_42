/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:57:28 by aumarin           #+#    #+#             */
/*   Updated: 2022/11/27 08:38:15 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	push_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_point *origin, t_point *dest, t_data *win)
{
	t_coordinates	starting;
	t_coordinates	ending;

	starting.x = origin->x_pixel;
	starting.y = origin->y_pixel;
	ending.x = dest->x_pixel;
	ending.y = dest->y_pixel;
	bresenham(starting, ending, win);
}

int	render_next_frame(void *t)
{
	(void)t;
	return (0);
}

void	init_window(t_mlx *mlx_data, t_map *map)
{
	t_data	img;
	t_point	*p;

	mlx_data->mlx = mlx_init();
	mlx_data->win = mlx_new_window(mlx_data->mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	mlx_loop_hook(mlx_data->mlx, render_next_frame, mlx_data);
	mlx_hook(mlx_data->win, 2, 1L << 0, on_key_press, &mlx_data);
	mlx_hook(mlx_data->win, 17, 1L << 0, on_close_press, &mlx_data);
	img.img = mlx_new_image(mlx_data->mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
								&img.line_length, &img.endian);
	p = map->points;
	while (p->next)
	{
		if (get_point(p->x + 1, p->y, p))
			draw_line(p, get_point(p->x + 1, p->y, p), &img);
		if (get_point(p->x, p->y + 1, p))
			draw_line(p, get_point(p->x, p->y + 1, p), &img);
		p = p->next;
	}
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, img.img, 0, 0);
	mlx_data->img = &img;
	mlx_loop(mlx_data->mlx);
	printf("Loop detruite !!!!\n");
	mlx_destroy_display(mlx_data->mlx);
}
