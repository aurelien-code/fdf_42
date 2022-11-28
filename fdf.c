/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:26:31 by aumarin           #+#    #+#             */
/*   Updated: 2022/11/28 12:55:20 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;
	t_mlx	*mlx_data;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	map = get_map(fd);
	if (!map || map->x_size == 0 || map->y_size == 0)
		return (1);
	close(fd);
	mlx_data = malloc(sizeof(t_data) * 1);
	if (!mlx_data)
		return (1);
	mlx_data->map = map;
	init_window(mlx_data, map);
	printf("Loop detruite 2!!!!\n");
	return (0);
}
