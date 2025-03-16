/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouafik <rmouafik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:53:53 by rmouafik          #+#    #+#             */
/*   Updated: 2025/03/16 15:03:54 by rmouafik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double cr, double ci)
{
	double zr, zi;
	double	tmp;
	int (i), (max_i);

	zi = 0;
	zr = 0;
	i = 0;
	max_i = 100;
	while (zr * zr + zi * zi <= 4 && i < max_i)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;
		i++;
	}
	return (i);
}

void	draw_mandelbrot(t_frac *fractol)
{
	int x;
	int y;
	int iter;
	double cr, ci;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cr = convert_pixel(x, -2, +2 , 0, WIDTH) * fractol->zoom;
			ci = convert_pixel(y, +2, -2 , 0, HEIGHT) * fractol->zoom;
			iter = mandelbrot(cr, ci);
			put_pixel(fractol, x, y, put_color(iter, 100));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->ptr, fractol->win, fractol->img, 0, 0);
}
int	julia(double zr, double zi, double cr, double ci)
{
	double	tmp;
	int		iter;
	int		max_iter;

	iter = 0;
	max_iter = 100;
	while (zr * zr + zi * zi <= 4 && iter < max_iter)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;
		iter++;
	}
	return (iter);
}

void	draw_julia(t_frac *fractol)
{
	int		x, y, iter;
	double	zr, zi;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			zr = convert_pixel(x, -2, +2 , 0, WIDTH) * fractol->zoom;
			zi = convert_pixel(y, +2, -2 , 0, HEIGHT) * fractol->zoom;
			iter = julia(zr, zi, fractol->julia_r, fractol->julia_i);
			put_pixel(fractol, x, y, put_color(iter, 100));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->ptr, fractol->win, fractol->img, 0, 0);
}
