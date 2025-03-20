/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouafik <rmouafik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:56:47 by rmouafik          #+#    #+#             */
/*   Updated: 2025/03/18 18:19:30 by rmouafik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	x_notify(t_frac *fractol)
{
	mlx_destroy_window(fractol->ptr, fractol->win);
	mlx_destroy_image(fractol->ptr, fractol->img);
	exit(0);
	return (0);
}

int	events_key(int keycode, t_frac *fractol)
{
	if (keycode == 53)
		x_notify(fractol);
	if (keycode == 69)
		fractol->depth += 10;
	if (keycode == 78)
		fractol->depth -= 10;
	if (keycode == 123)
		fractol->arrow_x += 0.05 * fractol->zoom;
	if (keycode == 124)
		fractol->arrow_x -= 0.05 * fractol->zoom;
	if (keycode == 125)
		fractol->arrow_y += 0.05 * fractol->zoom;
	if (keycode == 126)
		fractol->arrow_y -= 0.05 * fractol->zoom;
	if (fractol->flag == 0)
		draw_mandelbrot(fractol);
	else if (fractol->flag == 1)
		draw_julia(fractol);
	else
		draw_burn(fractol);
	return (0);
}

int	events_mouse(int button, int x, int y, t_frac *fractol)
{
	x = 0;
	y = 0;
	if (button == 5)
		fractol->zoom *= 1.1;
	else if (button == 4)
		fractol->zoom *= 0.9;
	if (fractol->flag == 0)
		draw_mandelbrot(fractol);
	else if (fractol->flag == 1)
		draw_julia(fractol);
	else
		draw_burn(fractol);
	return (0);
}

void	hooks(t_frac *fractol)
{
	mlx_hook(fractol->win, 17, 0, x_notify, fractol);
	mlx_key_hook(fractol->win, events_key, fractol);
	mlx_mouse_hook(fractol->win, events_mouse, fractol);
}
