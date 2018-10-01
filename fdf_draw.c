/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 19:24:27 by oskulska          #+#    #+#             */
/*   Updated: 2018/03/27 19:24:31 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	*while_temp(t_map *temp, int how)
{
	int	i;

	i = 0;
	while (i < how)
	{
		if (temp->next == NULL)
			return (temp);
		temp = temp->next;
		i++;
	}
	return (temp);
}

t_brz			*brz_int(t_map *tmp, t_map *temp, t_mlx *mlx)
{
	t_brz		*brz;

	brz = mlx->brz;
	brz->x0 = tmp->x;
	brz->y0 = tmp->y;
	brz->x1 = temp->x;
	brz->y1 = temp->y;
	brz->dx = abs(brz->x1 - brz->x0);
	brz->dy = abs(brz->y1 - brz->y0);
	brz->sx = brz->x0 < brz->x1 ? 1 : -1;
	brz->sy = brz->y0 < brz->y1 ? 1 : -1;
	brz->err = (brz->dx > brz->dy ? brz->dx : -brz->dy) / 2;
	return (brz);
}

void			put_pixel(int x, int y, t_mlx *mlx, int color)
{
	x = x + W_X / 2;
	y = y + W_Y / 2;
	if (x >= mlx->size_line / 4 || x < 0 || y < 0)
		return ;
	if (y * mlx->size_line / 4 + x < 1000000)
		mlx->str[y * mlx->size_line / 4 + x] = color;
}

void			line(t_map *tmp, t_map *temp, t_mlx *mlx)
{
	t_brz		*brz;

	brz = mlx->brz;
	brz = brz_int(tmp, temp, mlx);
	while (1)
	{
		put_pixel(brz->x0, brz->y0, mlx, tmp->color);
		if (brz->x0 == brz->x1 && brz->y0 == brz->y1)
			break ;
		brz->e = brz->err;
		if (brz->e > -brz->dx)
		{
			brz->err -= brz->dy;
			brz->x0 += brz->sx;
		}
		if (brz->e < brz->dy)
		{
			brz->err += brz->dx;
			brz->y0 += brz->sy;
		}
	}
}

void			print(t_mlx *mlx)
{
	int			i;
	t_map		*tmp;
	t_map		*temp;

	i = 0;
	tmp = mlx->begin;
	temp = mlx->begin;
	while (tmp)
	{
		if (tmp->next && i % (mlx->max_x) != 0)
			line(tmp, tmp->next, mlx);
		tmp = tmp->next;
		i++;
	}
	tmp = mlx->begin;
	i = -1;
	while (tmp)
	{
		if (++i > mlx->max_x * mlx->max_y - mlx->max_x)
			break ;
		(i > 0) ? temp = while_temp(tmp, mlx->max_x) : 0;
		line(tmp, temp, mlx);
		tmp = tmp->next;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}
