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

void	print_ll(t_map *map)
{
	t_point	*h;

	if (!map)
		return ;
	printf("Donnees de la LL => \n");
	h = map->points;
	while (h->next)
	{
		printf("x = %d, y = %d, z = %d\n", h->x, h->y, h->z);
		h = h->next;
	}
	printf("Fin de la LL\n");
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
		i = 0;
		while (split_line && split_line[i])
		{
			add_last(map, new_point(map->x_size, i, ft_atoi(split_line[i])));
			free(split_line[i]);
			i++;
		}
		map->x_size++;
		if (split_line)
			free(split_line);
		full_line = get_next_line(fd);
	}
	map->y_size = i;
}

t_map	*get_map(int fd)
{
	t_map		*map;

	map = malloc(sizeof(t_map) * 1);
	if (!map)
		return (NULL);
	map->x_size = 0;
	map->y_size = 0;
	map->points = NULL;
	read_map(fd, map);
	return (map);
}
