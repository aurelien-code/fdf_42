/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:26:31 by aumarin           #+#    #+#             */
/*   Updated: 2022/11/28 16:10:05 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		return (1);
	map = get_map(argv);
	if (!map || map->x_size == 0 || map->y_size == 0)
		return (1);
	init_window(map);
	printf("Fin du programme\n");
	return (0);
}
