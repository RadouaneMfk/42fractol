/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouafik <rmouafik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:46:51 by rmouafik          #+#    #+#             */
/*   Updated: 2025/03/20 16:01:14 by rmouafik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_valid_double(const char *str)
{
	int	dot;

	if (!str || !*str)
		return (0);
	dot = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str == '.' && dot == 0)
			dot = 1;
		else if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	parse_j(char *real_str, char *imag_str, double *real, double *imag)
{
	if (!is_valid_double(real_str) || !is_valid_double(imag_str))
	{
		ft_putstr_fd("Error: Invalid Julia parameters.\n", 2);
		exit(1);
	}
	*real = str_to_double(real_str);
	*imag = str_to_double(imag_str);
	return (1);
}
