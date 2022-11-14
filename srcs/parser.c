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
	t_point *h;

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

void	read_map(int fd, t_map *map_data)
{
	char	*full_line;
	char	**split_line;
	t_point	*p;
	int		i;

	full_line = get_next_line(fd);
	p = NULL;
	while (full_line)
	{
		if (!full_line)
			return ;
		split_line = ft_split(full_line, ' ');
		free(full_line);
		i = 0;
		while (split_line && split_line[i])
		{
			p = new_point(map_data->x_size, i, ft_atoi(split_line[i]));
			if (!p)
				return ;
			add_last(map_data, p);
			free(split_line[i]);
			i++;
		}
		map_data->x_size++;
		if (split_line)
			free(split_line);
		full_line = get_next_line(fd);
	}
	map_data->y_size = i;
	print_ll(map_data);
	printf("Fichier parse correctement !\n");
}

t_map	*get_map(int fd)
{
	t_map		*map_data;

	map_data = malloc(sizeof(t_map) * 1);
	if (!map_data)
		return (NULL);
	map_data->x_size = 0;
	map_data->y_size = 0;
	map_data->points = NULL;
	read_map(fd, map_data);
	free_points(map_data);
	free(map_data);
	return (NULL);
}
