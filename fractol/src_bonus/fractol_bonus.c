/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouafik <rmouafik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:45:25 by rmouafik          #+#    #+#             */
/*   Updated: 2025/03/18 14:03:36 by rmouafik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	put_pixel(t_frac *fractol, int x, int y, int color)
{
	char	*dst;

	dst = fractol->add + (y * fractol->line_len + x * (fractol->bpp / 8));
	*(unsigned int *)dst = color;
}

void	error_message(void)
{
	ft_putstr_fd
	("usage: ./fractol mandelbrot or ./fractol julia <real_num> <ima_num>", 2);
	ft_putstr_fd("or ./fractol burning_ship\n", 2);
	exit(1);
}

int	put_color(int i, int max_i)
{
	int	red;
	int	green;
	int	blue;

	if (i == max_i)
		return (0x000000);
	red = (i * (2 + (max_i % 2))) % 256;
	green = (i * (8 + (max_i % 8))) % 256; 
	blue = (i * (15 + (max_i % 15))) % 256;
	return ((red << 16) | (green << 8) | blue);
}

void	fractol_init(t_frac	*fractol)
{
	fractol->ptr = mlx_init();
	fractol->win = mlx_new_window(fractol->ptr, WIDTH, HEIGHT, "Fractol");
	fractol->img = mlx_new_image(fractol->ptr, WIDTH, HEIGHT);
	fractol->add = mlx_get_data_addr
		(fractol->img, &fractol->bpp, &fractol->line_len, &fractol->endian);
	fractol->zoom = 1.0;
	fractol->depth = 100;
	fractol->flag = 0;
}

int	main(int ac, char *av[])
{
	t_frac	fractol;

	fractol_init(&fractol);
	if (ac == 2 && ft_strncmp(av[1], "mandelbrot", 11) == 0)
	{
		draw_mandelbrot(&fractol);
	}
	else if (ac == 4 && ft_strncmp(av[1], "julia", 6) == 0)
	{
		fractol.flag = 1;
		fractol.julia_r = str_to_double(av[2]);
		fractol.julia_i = str_to_double(av[3]);
		draw_julia(&fractol);
	}
	else if (ac == 2 && ft_strncmp(av[1], "burning_ship", 13) == 0)
	{
		fractol.flag = 2;
		draw_burn(&fractol);
	}
	else
		error_message();
	hooks(&fractol);
	mlx_loop(fractol.ptr);
}
