/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 00:05:55 by aumarin           #+#    #+#             */
/*   Updated: 2022/10/28 15:55:02 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_file_ext_valid(char *path)
{
	return (1);
	return (0);
}

long int	calculate_map_size(int fd)
{
	long int	x_size;
	long int	y_size;

	x_size = 0;
	y_size = 0;
	(void)fd;
	return (x_size * y_size);
}

t_coordinates	*get_map(int fd)
{
	char			*full_line;
	char			**split_line;
	int				x_value;
	int				y_value;
	t_map_data		*map_data;
	t_coordinates	*map;

	map = malloc(sizeof(t_coordinates) * 10);
	(void)map;
	map_data = malloc(sizeof(map_data) * 1);
	map_data->x_size = 0;
	map_data->y_size = 0;
	x_value = 0;
	y_value = 0;
	full_line = malloc(sizeof(char) * 1);
	if (!full_line)
		return (NULL);
	printf("fd -> %d\n", fd);
	while (full_line)
	{
		free(full_line);
		full_line = get_next_line(fd);
		if (full_line)
		{
			printf("[%x] %s", x_value, full_line);
			split_line = ft_split(full_line, ' ');
			printf("[%x'] ", x_value);
			while (split_line[y_value])
			{
				printf("%s ", split_line[y_value]);
				free(split_line[y_value]);
				y_value++;
			}
			free(split_line);
			y_value = 0;
			x_value++;
		}
	}
	return (map);
}

