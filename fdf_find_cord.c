/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_find_cord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 19:22:27 by oskulska          #+#    #+#             */
/*   Updated: 2018/03/27 19:22:31 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	get_zoom(t_mlx *mlx)
{
	if (W_X - (mlx->max_x) > W_Y - (mlx->max_y))
		mlx->zoom = (W_X / 2) - W_X / mlx->max_x;
	else
		mlx->zoom = (W_Y / 2) - W_Y / mlx->max_y;
}

static void		start_fdf(t_mlx *mlx)
{
	t_map		*tmp;

	tmp = mlx->begin;
	while (tmp)
	{
		tmp->x = (2 * tmp->x - (mlx->max_x - 1)) / (mlx->max_x - 1);
		tmp->y = (2 * tmp->y - (mlx->max_y - 1)) / (mlx->max_y - 1);
		tmp->z /= mlx->max_z;
		tmp = tmp->next;
	}
	tmp = mlx->begin;
	while (tmp)
	{
		tmp->x = tmp->x * mlx->zoom;
		tmp->y = tmp->y * mlx->zoom;
		tmp->z = tmp->z * mlx->zoom / 4;
		tmp = tmp->next;
	}
}

void			find_new_cord(t_mlx *mlx)
{
	t_map		*tmp;

	tmp = mlx->begin;
	while (tmp)
	{
		mlx->max_x = tmp->x;
		mlx->max_y = tmp->y;
		mlx->max_z = tmp->z > mlx->max_z ? tmp->z : mlx->max_z;
		tmp = tmp->next;
	}
	mlx->max_x += 1;
	mlx->max_y += 1;
	get_zoom(mlx);
	start_fdf(mlx);
}
