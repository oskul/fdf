/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:35:59 by oskulska          #+#    #+#             */
/*   Updated: 2018/03/27 18:36:02 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_clear(char **arr, char *line)
{
	size_t	count;

	count = 0;
	while (arr[count])
	{
		free(arr[count]);
		arr[count] = NULL;
		count++;
	}
	free(arr);
	arr = NULL;
	free(line);
	line = NULL;
}

void	exit_free(char **str, char *line)
{
	ft_putstr("Found wrong line length. Exiting.2\n");
	ft_clear(str, line);
	exit(1);
}

void	check_exit_ret(int ret, int flag)
{
	if (ret == -1 || (ret == 0 && flag == 0))
	{
		ft_putstr("No data found.\n");
		exit(1);
	}
}

void	check_len(int x, int y, t_mlx *mlx, char **str)
{
	if (x == -1 && y == 0)
		mlx->len = count_len(str);
	if (mlx->len != count_len(str))
	{
		ft_putstr("Found wrong line length. Exiting.1\n");
		exit(1);
	}
}

void	read_map(int fd, t_mlx *mlx, int y, int x)
{
	t_map	*map;
	char	*line;
	char	**str;

	map = mlx->begin;
	while ((mlx->ret = get_next_line(fd, &line)) > 0)
	{
		x = -1;
		mlx->flag_read = 1;
		str = ft_strsplit(line, ' ');
		check_len(x, y, mlx, str);
		if (ft_strlen(line) == 0)
			exit_free(str, line);
		while (str[++x])
		{
			if (x == 0 && y == 0)
				find_cord(map, x, y, str[x]);
			map->next = init_map();
			map = map->next;
			find_cord(map, x, y, str[x]);
		}
		y++;
		ft_clear(str, line);
	}
	check_exit_ret(mlx->ret, mlx->flag_read);
}
