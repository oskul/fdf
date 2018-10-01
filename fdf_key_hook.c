/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 19:19:57 by oskulska          #+#    #+#             */
/*   Updated: 2018/03/27 19:20:00 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		show_tools(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr,
		mlx->win_ptr, 50, 50, 0X33FFB2, "Press '*' - to show tools");
	if (mlx->flag == 1)
	{
		mlx_string_put(mlx->mlx_ptr,
			mlx->win_ptr, 50, 70, 0X33FFB2, "Press '+' - zoom in");
		mlx_string_put(mlx->mlx_ptr,
			mlx->win_ptr, 50, 90, 0X33FFB2, "Press '-' - zoom out");
		mlx_string_put(mlx->mlx_ptr,
			mlx->win_ptr, 50, 110, 0X33FFB2, "Press '5' - rotate up");
		mlx_string_put(mlx->mlx_ptr,
			mlx->win_ptr, 50, 130, 0X33FFB2, "Press '2' - rotate down");
		mlx_string_put(mlx->mlx_ptr,
			mlx->win_ptr, 50, 150, 0X33FFB2, "Press '1' - rotate left");
		mlx_string_put(mlx->mlx_ptr,
			mlx->win_ptr, 50, 170, 0X33FFB2, "Press '3' - rotate right");
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 400, 70, 0X33FFB2,
			"Press 'Up Arrow' - rotate Z axis left");
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 400, 90, 0X33FFB2,
			"Press 'Up Down' - rotate Z axis right");
	}
}

static void		key_hook_rotate_plus(int keycode, t_mlx *mlx)
{
	if (keycode == 87)
	{
		mlx->deg = 2;
		rotate(mlx, 1, 0, 0);
	}
	else if (keycode == 83)
	{
		mlx->deg = 2;
		rotate(mlx, 0, 1, 0);
	}
	else if (keycode == 125)
	{
		mlx->deg = 2;
		rotate(mlx, 0, 0, 1);
	}
}

static void		key_hook_rotate_minus(int keycode, t_mlx *mlx)
{
	if (keycode == 84)
	{
		mlx->deg = -2;
		rotate(mlx, 1, 0, 0);
	}
	else if (keycode == 85)
	{
		mlx->deg = -2;
		rotate(mlx, 0, 1, 0);
	}
	else if (keycode == 126)
	{
		mlx->deg = -2;
		rotate(mlx, 0, 0, 1);
	}
}

int				key_hook(int keycode, t_mlx *mlx)
{
	t_map		*tmp;

	tmp = mlx->begin;
	if (keycode == 53)
		exit(1);
	else if (keycode == 87 || keycode == 83 || keycode == 125)
		key_hook_rotate_plus(keycode, mlx);
	else if (keycode == 84 || keycode == 85 || keycode == 126)
		key_hook_rotate_minus(keycode, mlx);
	else if (keycode == 69)
		new_scale(mlx, 1.01);
	else if (keycode == 78)
		new_scale(mlx, 0.95);
	img_init(mlx);
	if (keycode == 67)
		mlx->flag = 1;
	show_tools(mlx);
	return (0);
}
