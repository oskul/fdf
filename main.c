/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:29:29 by oskulska          #+#    #+#             */
/*   Updated: 2018/03/27 18:30:17 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	check_usage(void)
{
	ft_putstr("Usage : ./fdf <filename> \n");
	exit(1);
}

static void	check_fd(int fd)
{
	if (fd == -1)
	{
		ft_putstr("No data found.\n");
		exit(1);
	}
}

void		img_init(t_mlx *mlx)
{
	int		a;
	int		endian;

	if (mlx->img_ptr != NULL)
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, W_X, W_Y);
	mlx->str = (int*)mlx_get_data_addr(mlx->img_ptr,
		&a, &mlx->size_line, &endian);
	print(mlx);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		50, 50, 0X33FFB2, "Press '*' - to show tools");
}

int			main(int ac, char **av)
{
	t_mlx	*mlx;
	int		fd;
	int		x;
	int		y;

	y = 0;
	x = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		check_fd(fd);
		mlx = init_mlx();
		mlx->mlx_ptr = mlx_init();
		mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, W_X, W_Y, "FDF OSKULSKA");
		read_map(fd, mlx, y, x);
		find_new_cord(mlx);
		img_init(mlx);
		mlx_hook(mlx->win_ptr, 2, 5, key_hook, mlx);
		mlx_loop(mlx->mlx_ptr);
	}
	else
		check_usage();
	return (0);
}
