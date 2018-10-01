/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_lib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 19:15:09 by oskulska          #+#    #+#             */
/*   Updated: 2018/03/27 19:15:11 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx		*init_mlx(void)
{
	t_mlx	*mlx;
	t_map	*map;

	map = init_map();
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->brz = (t_brz *)malloc(sizeof(t_brz));
	mlx->begin = map;
	mlx->deg = 2;
	mlx->flag_read = 0;
	mlx->zoom = 100;
	mlx->max_z = 0;
	return (mlx);
}

t_map		*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->x = 0;
	map->y = 0;
	map->z = 0;
	map->color = 0xFFFFFF;
	map->next = NULL;
	return (map);
}

int			count_len(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			ft_check(char c)
{
	int		nbr;
	int		i;
	char	*str;

	nbr = 0;
	i = 0;
	str = "0123456789ABCDEFabcdef";
	while (str[i] != '\0')
	{
		if (str[i] == ft_toupper(c))
			return (i);
		i++;
	}
	return (-1);
}

int			ft_pow(int nbr, int pow)
{
	int		res;

	res = 1;
	while (pow > 0)
	{
		res *= nbr;
		pow--;
	}
	return (res);
}
