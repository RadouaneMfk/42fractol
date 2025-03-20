/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouafik <rmouafik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:46:02 by rmouafik          #+#    #+#             */
/*   Updated: 2025/03/20 16:01:07 by rmouafik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include <math.h>
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
	double	arrow_x;
	double	arrow_y;
	int		flag;
	int		depth;
}	t_frac;

void		put_pixel(t_frac *fractol, int x, int y, int color);
int			put_color(int i, int max_i);
void		draw_mandelbrot(t_frac *fractol);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putstr_fd(char *s, int fd);
double		str_to_double(char *str);
void		hooks(t_frac *fractol);
void		draw_julia(t_frac *fractol);
void		draw_burn(t_frac *fractol);
int			parse_j(char *real_str, char *imag_str, double *real, double *imag);
#endif