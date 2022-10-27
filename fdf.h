/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:47:30 by aumarin           #+#    #+#             */
/*   Updated: 2022/10/27 22:42:13 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>

typedef struct s_coordinate
{
	int	x;
	int	y;
	int	z;
	int	x_pixel;
	int	y_pixel;
}	t_coordinates;


#endif