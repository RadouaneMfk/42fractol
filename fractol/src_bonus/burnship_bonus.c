/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burnship_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouafik <rmouafik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:59:04 by rmouafik          #+#    #+#             */
/*   Updated: 2025/03/18 14:14:01 by rmouafik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	burn(double cr, double ci, t_frac *fractol)
{
	int (i);
	double (zr), (zi), (tmp);
	zi = 0;
	zr = 0;
	i = 0;
	while (i < fractol->depth)
	{
		if (zr * zr + zi * zi >= 4)
			break ;
		tmp = fabs(zr * zr - zi * zi + cr);
		zi = fabs(2 * zr * zi + ci);
		zr = tmp;
		i++;
	}
	return (i);
}

void	draw_burn(t_frac *fractol)
{
	int (x), (y), (iter);
	float (cr), (ci);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cr = (-2.0 + ((x / (float)WIDTH) * (2.0 - (-2.0))))
				* fractol->zoom + fractol->arrow_x;
			ci = (2.0 - ((y / (float)HEIGHT) * (2.0 - (-2.0))))
				* fractol->zoom + fractol->arrow_y;
			iter = burn(cr, ci, fractol);
			put_pixel(fractol, x, y, put_color(iter, fractol->depth));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->ptr, fractol->win, fractol->img, 0, 0);
}
