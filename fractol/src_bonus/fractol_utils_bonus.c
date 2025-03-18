/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouafik <rmouafik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:53:56 by rmouafik          #+#    #+#             */
/*   Updated: 2025/03/17 16:54:40 by rmouafik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((unsigned char)s1[i] != '\0' 
		&& (unsigned char)s2[i] != '\0' && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

void	before_point(char *str, int *i, int *sign, double *res)
{
	*i = 0;
	*res = 0;
	*sign = 1;
	while ((str[*i] == 32) || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*res = (*res * 10) + (str[*i] - '0');
		(*i)++;
	}
}

double	str_to_double(char *str)
{
	double	res;
	double	f_res;
	int		i;
	int		sign;

	f_res = 0.1;
	before_point(str, &i, &sign, &res);
	if (str[i] == '.')
	{
		i++;
		while ((str[i] >= '0' && str[i] <= '9') && str[i])
		{
			res += (str[i] - '0') * f_res;
			f_res *= 0.1;
			i++;
		}
	}
	return (res * sign);
}
