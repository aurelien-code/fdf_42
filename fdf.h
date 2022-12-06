/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:47:30 by aumarin           #+#    #+#             */
/*   Updated: 2022/12/06 02:57:40 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h> //DO NOT FORGET : replace with ft_printf before submit
# include "./includes/libft/libft.h"
# include "./includes/minilibx-linux/mlx.h"
# include "./includes/ft_printf/ft_printf.h"

# define RAD_30 0.523599
# define RAD_45 0.785398
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define WHITE 0xFFFFFF
# define KEY_ESC 65307

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
	int		zoom;
	int		depth;
	t_point	*points;
}	t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_data	*img;
	t_map	*map;
}	t_mlx;

typedef struct s_coordinates
{
	int	x;
	int	y;
}	t_coordinates;

t_map	*get_map(char **line);
t_point	*add_last(t_map *map, t_point *point);
t_point	*new_point(int x, int y, int z, t_map *map);
t_point	*get_point(int x, int y, t_point *head);
void	free_points(t_map *map);
void	init_window(t_map *map);
void	push_pixel(t_data data, int x, int y, int color);
int		on_key_press(int keycode, t_mlx *mlx);
void	bresenham(t_coordinates s, t_coordinates e, t_data win);
void	clean_exit(t_mlx mlx_data);

#endif