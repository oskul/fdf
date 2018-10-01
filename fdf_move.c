/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 19:09:32 by oskulska          #+#    #+#             */
/*   Updated: 2018/03/27 19:09:34 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	new_scale(t_mlx *mlx, float a)
{
	t_map	*tmp;

	tmp = mlx->begin;
	while (tmp)
	{
		tmp->x *= a;
		tmp->y *= a;
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
}

void	rotate(t_mlx *mlx, double a, double b, double c)
{
	t_map	*tmp;
	float	x;
	float	y;
	float	z;
	double	deg;

	deg = (mlx->deg * M_PI) / 180;
	tmp = mlx->begin;
	while (tmp)
	{
		y = tmp->y;
		z = tmp->z;
		x = tmp->x;
		tmp->x = x * (cos(deg) + (1 - cos(deg)) * a * a) +
		y * (((1 - cos(deg)) * a * b + sin(deg) * c)) +
		z * (((1 - cos(deg)) * a * c - sin(deg) * b));
		tmp->y = x * (((1 - cos(deg)) * a * b - sin(deg) * c)) +
		y * (cos(deg) + (1 - cos(deg)) * b * b) +
		z * (((1 - cos(deg)) * b * c + sin(deg) * a));
		tmp->z = x * (((1 - cos(deg)) * a * c + sin(deg) * b)) +
		y * (((1 - cos(deg)) * b * c - sin(deg) * a)) +
		z * (((1 - cos(deg)) * c * c + cos(deg)));
		tmp = tmp->next;
	}
}
