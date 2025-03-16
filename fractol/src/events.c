/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouafik <rmouafik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:53:57 by rmouafik          #+#    #+#             */
/*   Updated: 2025/03/16 14:44:11 by rmouafik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int x_notify(t_frac *fractol)
{
	mlx_destroy_window(fractol->ptr, fractol->win);
	mlx_destroy_image(fractol->ptr, fractol->img);
	exit(0);
	return (0);
}

int events_key(int keycode, t_frac *fractol)
{
	if (keycode == 53)
		x_notify(fractol);
	return (0);
}

int events_mouse(int button, int x, int y, t_frac *fractol)
{
	if (button == 5)
		fractol->zoom *= 1.1;
	else if (button == 4)
		fractol->zoom *= 0.9;
	if (fractol->flag == 0)
		draw_mandelbrot(fractol);
	else
		draw_julia(fractol);
	return (0);
}
void hooks(t_frac *fractol)
{
	mlx_hook(fractol->win, 17, 0, x_notify, fractol);
	mlx_key_hook(fractol->win, events_key, fractol);
	mlx_mouse_hook(fractol->win, events_mouse, fractol);
}
