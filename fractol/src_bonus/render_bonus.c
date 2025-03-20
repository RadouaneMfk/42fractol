/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouafik <rmouafik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:55:26 by rmouafik          #+#    #+#             */
/*   Updated: 2025/03/18 15:05:20 by rmouafik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	mandelbrot(double cr, double ci, t_frac *fractol)
{
	double (zr), (zi), (tmp);
	int (i);
	zi = 0;
	zr = 0;
	i = 0;
	while (i < fractol->depth)
	{
		if (zr * zr + zi * zi >= 4)
			break ;
		tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;
		i++;
	}
	return (i);
}

void	draw_mandelbrot(t_frac *fractol)
{
	int (x), (y), (iter);
	float (cr), (ci);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cr = (-2.0 + ((x / (double)WIDTH) * (2.0 - (-2.0))))
				* fractol->zoom + fractol->arrow_x;
			ci = (2.0 - ((y / (double)HEIGHT) * (2.0 - (-2.0))))
				* fractol->zoom + fractol->arrow_y;
			iter = mandelbrot(cr, ci, fractol);
			put_pixel(fractol, x, y, put_color(iter, fractol->depth));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->ptr, fractol->win, fractol->img, 0, 0);
}

int	julia(double zr, double zi, t_frac *fractol)
{
	double	tmp;
	int		iter;

	iter = 0;
	while (iter < fractol->depth)
	{
		if (zr * zr + zi * zi >= 4)
			break ;
		tmp = zr * zr - zi * zi + fractol->julia_r;
		zi = 2 * zr * zi + fractol->julia_i;
		zr = tmp;
		iter++;
	}
	return (iter);
}

void	draw_julia(t_frac *fractol)
{
	double (zr), (zi);
	int (x), (y), (iter);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			zr = (-2.0 + ((x / (double)WIDTH) * (2.0 - (-2.0))))
				* fractol->zoom + fractol->arrow_x;
			zi = (2.0 - ((y / (double)HEIGHT) * (2.0 - (-2.0))))
				* fractol->zoom + fractol->arrow_y;
			iter = julia(zr, zi, fractol);
			put_pixel(fractol, x, y, put_color(iter, fractol->depth));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->ptr, fractol->win, fractol->img, 0, 0);
}
