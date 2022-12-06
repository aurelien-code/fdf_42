/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 00:05:55 by aumarin           #+#    #+#             */
/*   Updated: 2022/12/06 03:04:00 by aumarin          ###   ########.fr       */
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

void	read_map(int fd, t_map *map)
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
		i = -1;
		while (split_line && split_line[++i])
		{
			add_last(map, new_point(i, map->y_size, ft_atoi(split_line[i]), \
				map));
			free(split_line[i]);
		}
		add_last(map, new_point(i + 1, 0, 0, map));
		map->y_size++;
		if (split_line)
			free(split_line);
		full_line = get_next_line(fd);
		map->x_size = i;
	}
}

void	optimum_zoom(int x, int y)
{
	int	zoom;
	int	yoom;

	yoom = 0;
	zoom = 0;
	if (x <= 0 || y <= 0)
		return ;
	while ((x + y) * zoom < WIN_WIDTH)
		zoom++;
	while ((((x + y) * yoom) / 2) < WIN_HEIGHT)
		yoom++;
}

t_map	*get_map(char **argv)
{
	t_map		*map;
	int			fd;

	if (!is_file_fdf(argv[1]))
		return (NULL);
	if (open(argv[1], O_DIRECTORY) >= 0)
		return (NULL);
	map = malloc(sizeof(t_map) * 1);
	if (!map)
		return (NULL);
	map->zoom = 30;
	map->depth = 30;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (NULL);
	map->x_size = 0;
	map->y_size = 0;
	map->points = NULL;
	read_map(fd, map);
	optimum_zoom(map->x_size, map->y_size);
	close(fd);
	return (map);
}
