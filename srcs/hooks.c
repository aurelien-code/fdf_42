/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:21:41 by aumarin           #+#    #+#             */
/*   Updated: 2022/11/27 07:45:59 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	printf("Cross pressed\n");
	(void)keycode;
	(void)mlx_data;
	return (0);
}
