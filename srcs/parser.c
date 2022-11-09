/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 00:05:55 by aumarin           #+#    #+#             */
/*   Updated: 2022/11/09 16:57:05 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_file_fdf(char *path)
{
	char	*sub_str;

	sub_str = ft_strchr(path, '.');
	if (ft_strlen(sub_str) != 4)
		return (0);
	if (ft_strncmp(sub_str, ".fdf", 4) != 0)
		return (0);
	return (1);
}

void	add_point(t_map *md, int x, int y, int z)
{
	t_point	*point;
	(void)md;
	point = malloc(sizeof(t_point) * 1);
	if (!point)
		return ;
	point->x = x;
	point->y = y;
	point->z = z;
	point->x_pixel = -1;
	point->y_pixel = -1;
	printf("-> x = %d, y = %d, z = %d\n", point->x, point->y, point->z);

}

void	read_map(int fd, t_map *map_data)
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
			add_point(map_data, map_data->x_size, i, ft_atoi(split_line[i]));
			free(split_line[i]);
			i++;
		}
		map_data->x_size++;
		if (split_line)
			free(split_line);
		full_line = get_next_line(fd);
	}
	map_data->y_size = i;
	printf("Fichier parse correctement !\n");
}

t_map	*get_map(int fd)
{
	t_map		*map_data;

	map_data = malloc(sizeof(t_map) * 1);
	map_data->x_size = 0;
	map_data->y_size = 0;
	if (!map_data)
		return (NULL);
	read_map(fd, map_data);
	printf("Dim = %d,%d\n", map_data->x_size, map_data->y_size);
	free(map_data);
	return (NULL);
}
