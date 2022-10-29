/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:47:30 by aumarin           #+#    #+#             */
/*   Updated: 2022/10/28 03:41:16 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h> //DO NOT FORGET : replace with ft_printf before submit
# include "./includes/libft/libft.h"

typedef struct s_coordinate
{
	int	x;
	int	y;
	int	z;
	int	x_pixel;
	int	y_pixel;
}	t_coordinates;

typedef struct s_map_data
{
	int	x_size;
	int	y_size;
}	t_map_data;

t_coordinates	*get_map(int fd);

#endif