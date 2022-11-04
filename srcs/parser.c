/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 00:05:55 by aumarin           #+#    #+#             */
/*   Updated: 2022/11/03 21:37:26 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

long int	calculate_map_size(int fd)
{
	long int	x_size;
	long int	y_size;

	x_size = 0;
	y_size = 0;
	(void)fd;
	return (x_size * y_size);
}

void	add_point(t_map_data *map_data, int y, int z)
{
	printf("-> x = %d, y = %d, z = %d\n", map_data->x_size, y, z);
}

void	set_map_dimensions(int fd, t_map_data *map_data)
{
	char	*full_line;
	char	**split_line;
	int		i;

	full_line = get_next_line(fd);
	while (full_line)
	{
		if (!full_line)
			return ;
		split_line = ft_split(full_line, ' ');
		free(full_line);
		i = 0;
		while (split_line && split_line[i])
		{
			add_point(map_data, i, ft_atoi(split_line[i]));
			free(split_line[i]);
			i++;
		}
		map_data->x_size++;
		map_data->y_size = i;
		if (split_line)
			free(split_line);
		full_line = get_next_line(fd);
	}
	printf("Fichier parse correctement !\n");
}

t_map_data	*get_map(int fd)
{
	t_map_data		*map_data;

	map_data = malloc(sizeof(t_map_data) * 1);
	map_data->x_size = 0;
	map_data->y_size = 0;
	if (!map_data)
		return (NULL);
	set_map_dimensions(fd, map_data);
	printf("Dim = %d,%d\n", map_data->x_size, map_data->y_size);
	//set_map_points(fd, map_data);
	free(map_data);
	return (NULL);
}
