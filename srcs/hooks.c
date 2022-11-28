/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:21:41 by aumarin           #+#    #+#             */
/*   Updated: 2022/11/28 19:51:58 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clean_exit(t_mlx mlx_data)
{
	if (mlx_data.mlx && mlx_data.img->img && mlx_data.win)
	{
		mlx_destroy_image(mlx_data.mlx, mlx_data.img->img);
		free_points(mlx_data.map);
		free(mlx_data.map);
		mlx_destroy_window(mlx_data.mlx, mlx_data.win);
		mlx_destroy_display(mlx_data.mlx);
		free(mlx_data.mlx);
	}
}

int	on_key_press(int keycode, t_mlx *mlx_data)
{
	if (keycode == KEY_ESC)
	{
		printf("ESC pressed\n");
		mlx_loop_end(mlx_data->mlx);
	}
	return (0);
}

int	on_close_press(int keycode, t_mlx *mlx_data)
{
	(void)keycode;
	printf("Cross pressed\n");
	if (mlx_data->mlx)
		mlx_loop_end(mlx_data->mlx);
	return (0);
}
