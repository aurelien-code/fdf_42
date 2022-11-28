/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:47:30 by aumarin           #+#    #+#             */
/*   Updated: 2022/11/28 18:32:21 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h> //DO NOT FORGET : replace with ft_printf before submit
# include "./includes/libft/libft.h"
# include "./includes/minilibx-linux/mlx.h"

# define RAD_30 0.523599
# define SCALE 20
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define WHITE 0xFFFFFF
# define YELLOW 0x00FFFF00
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
t_point	*new_point(int x, int y, int z, int zoom);
t_point	*get_point(int x, int y, t_point *head);
void	free_points(t_map *map);
void	init_window(t_map *map);
void	push_pixel(t_data data, int x, int y, int color);
int		on_key_press(int keycode, t_mlx *mlx);
int		on_close_press(int keycode, t_mlx *mlx);
void	bresenham(t_coordinates s, t_coordinates e, t_data win);
void	clean_exit(t_mlx mlx_data);

#endif