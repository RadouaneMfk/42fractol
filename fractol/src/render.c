/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouafik <rmouafik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:53:53 by rmouafik          #+#    #+#             */
/*   Updated: 2025/03/19 14:10:07 by rmouafik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double cr, double ci)
{
	double (zr), (zi), (tmp);
	int (i), (max_i);
	zi = 0;
	zr = 0;
	i = 0;
	max_i = 100;
	while (i < max_i)
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
	double (cr), (ci);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cr = (-2.0 + ((x / (double)WIDTH) * (2.0 - (-2.0))))
				* fractol->zoom;
			ci = (2.0 - ((y / (double)HEIGHT) * (2.0 - (-2.0))))
				* fractol->zoom;
			iter = mandelbrot(cr, ci);
			put_pixel(fractol, x, y, put_color(iter, 100));
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
	int		max_iter;

	iter = 0;
	max_iter = 100;
	while (iter < max_iter)
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
				* fractol->zoom;
			zi = (2.0 - ((y / (double)HEIGHT) * (2.0 - (-2.0))))
				* fractol->zoom;
			iter = julia(zr, zi, fractol);
			put_pixel(fractol, x, y, put_color(iter, 100));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->ptr, fractol->win, fractol->img, 0, 0);
}
