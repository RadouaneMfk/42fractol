/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouafik <rmouafik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:07:12 by rmouafik          #+#    #+#             */
/*   Updated: 2025/03/20 16:01:21 by rmouafik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_frac *fractol, int x, int y, int color)
{
	char	*dst;

	dst = fractol->add + (y * fractol->line_len + x * (fractol->bpp / 8));
	*(unsigned int *)dst = color;
}

void	error_message(void)
{
	ft_putstr_fd
	("usage: ./fractol mandelbrot or ./fractol julia <real_num> <ima_num>\n", 2);
	exit(1);
}

int	put_color(int i, int max_i)
{
	int	red;
	int	green;
	int	blue;

	if (i == max_i)
		return (0x000000);
	red = (i * 2) % 256;
	green = (i * 8) % 256;
	blue = (i * 15) % 256;
	return ((red << 16) | (green << 8) | blue);
}

int	main(int ac, char *av[])
{
	t_frac	fractol;

	fractol.ptr = mlx_init();
	fractol.win = mlx_new_window(fractol.ptr, WIDTH, HEIGHT, "Fractol");
	fractol.img = mlx_new_image(fractol.ptr, WIDTH, HEIGHT);
	fractol.add = mlx_get_data_addr
		(fractol.img, &fractol.bpp, &fractol.line_len, &fractol.endian);
	fractol.zoom = 1.0;
	fractol.flag = 0;
	if (ac == 2 && ft_strncmp(av[1], "mandelbrot", 11) == 0)
		draw_mandelbrot(&fractol);
	else if (ac == 4 && ft_strncmp(av[1], "julia", 6) == 0)
	{
		fractol.flag = 1;
		parse_j(av[2], av[3], &fractol.julia_r, &fractol.julia_i);
		draw_julia(&fractol);
	}
	else
		error_message();
	hooks(&fractol);
	mlx_loop(fractol.ptr);
}
