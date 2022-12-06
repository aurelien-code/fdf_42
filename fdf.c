/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:26:31 by aumarin           #+#    #+#             */
/*   Updated: 2022/12/06 03:03:31 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		return (1);
	map = get_map(argv);
	if (!map)
		return (1);
	if (map->x_size == 0 || map->y_size == 0)
	{
		free(map);
		return (1);
	}
	init_window(map);
	ft_putstr_fd("Fin du programme\n", 1);
	return (0);
}
