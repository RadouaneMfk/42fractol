/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouafik <rmouafik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:07:02 by rmouafik          #+#    #+#             */
/*   Updated: 2025/03/20 16:00:56 by rmouafik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# define WIDTH 800
# define HEIGHT 800

typedef struct s_frac
{
	void	*ptr;
	void	*win;
	void	*img;
	char	*add;
	int		bpp;
	int		line_len;
	int		endian;
	double	zoom;
	double	julia_r;
	double	julia_i;
	int		flag;
}	t_frac;

void		put_pixel(t_frac *fractol, int x, int y, int color);
int			parse_j(char *real_str, char *imag_str, double *real, double *imag);
int			put_color(int i, int max_i);
int			mandelbrot(double cr, double ci);
void		draw_mandelbrot(t_frac *fractol);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putstr_fd(char *s, int fd);
double		str_to_double(char *str);
void		hooks(t_frac *fractol);
void		draw_julia(t_frac *fractol);
#endif