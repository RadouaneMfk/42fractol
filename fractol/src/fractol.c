/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouafik <rmouafik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:07:12 by rmouafik          #+#    #+#             */
/*   Updated: 2025/03/16 16:27:30 by rmouafik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_frac *fractol, int x, int y, int color)
{
	char *dst;

	dst = fractol->add + (y * fractol->line_len + x * (fractol->bpp / 8));
	*(unsigned int*)dst = color;
}

double	convert_pixel(double unscaledNum, double minAllowed, double maxAllowed, double min, double max)
{
	return ((maxAllowed - minAllowed) * (unscaledNum - min) / (max - min) + minAllowed);
}

int	put_color(int i, int max_i)
{
	int	red;
	int	green;
	int	blue;

	if (i == max_i)
		return (0x000000);
	red = (i * 1) % 256;
	green = (i * 15) % 256;
	blue = (i * 15) % 256;
	return ((red << 16) | (green << 8) | blue);
}

int main(int ac, char *av[])
{
	t_frac fractol;
	fractol.ptr = mlx_init();
	fractol.win = mlx_new_window(fractol.ptr, WIDTH, HEIGHT, "Fractol");
	fractol.img = mlx_new_image(fractol.ptr, WIDTH, HEIGHT);
	fractol.add = mlx_get_data_addr(fractol.img, &fractol.bpp, &fractol.line_len, &fractol.endian);
	fractol.zoom = 1.0;
	fractol.flag = 0;
	if (ac == 2 && ft_strncmp(av[1], "Mandelbrot", 11) == 0)
		draw_mandelbrot(&fractol);
	else if (ac == 4 && ft_strncmp(av[1], "Julia", 6) == 0)
	{
		fractol.flag = 1;
		fractol.julia_r = str_to_double(av[2]);
		fractol.julia_i = str_to_double(av[3]);
		draw_julia(&fractol);
	}
	else
	{
		ft_putstr_fd("->correct usage: ./fractol Mandelbrot or ./fractol Julia <real_num> <ima_num>\n", 2);
		exit(1);
	}
	hooks(&fractol);
	mlx_loop(fractol.ptr);
}
