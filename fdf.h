/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:47:30 by aumarin           #+#    #+#             */
/*   Updated: 2022/11/03 21:40:53 by aumarin          ###   ########.fr       */
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
	int		x;
	int		y;
	int		z;	
	int		x_pixel;
	int		y_pixel;
	t_point	*next;
}	t_point;

typedef struct s_map_data
{
	int		x_size;
	int		y_size;
	t_point	*points;
}	t_map_data;

t_map_data	*get_map(int fd);

#endif