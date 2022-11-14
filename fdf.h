/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:47:30 by aumarin           #+#    #+#             */
/*   Updated: 2022/11/09 17:53:38 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h> //DO NOT FORGET : replace with ft_printf before submit
# include "./includes/libft/libft.h"

typedef struct s_point
{
	int				x;
	int				y;
	int				z;	
	int				x_pixel;
	int				y_pixel;
	struct s_point	*next;
}	t_point;

typedef struct s_map
{
	int		x_size;
	int		y_size;
	t_point	*points;
}	t_map;

t_map	*get_map(int fd);
t_point	*add_last(t_map *map, t_point *point);
t_point *new_point(int x, int y, int z);
void	free_points(t_map *map);

#endif