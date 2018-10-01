/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str,size_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <oskulska@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 15:47:00 by oskulska          #+#    #+#             */
/*   Updated: 2018/03/17 15:47:00 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_atoi_base(char *str, int base)
{
	int		nbr;
	int		pow;
	int		c;

	nbr = 0;
	c = 1;
	pow = ft_strlen(str) - 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			c = -1;
		str++;
	}
	while (ft_check(*str) != -1 && *str)
	{
		nbr += ft_check(*str) * ft_pow(base, pow);
		pow--;
		str++;
	}
	return (nbr * c);
}

static void	check_is_alpha(int k, char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (ft_isalpha(s[i]))
		{
			if (k == 1)
				free(s);
			ft_putstr("Map error : wrong color format");
			exit(1);
		}
		i++;
	}
}

void		find_cord(t_map *map, int x, int y, char *str)
{
	int		i;

	i = 0;
	map->y = y;
	map->x = x;
	map->z = ft_atoi(str);
	map->color = 0xccdbff;
	if (ft_strchr(str, ','))
		find_color(str, map);
	if (!ft_strchr(str, ','))
		check_is_alpha(0, str);
}

static void	ft_exit(void)
{
	ft_putstr("Map error : wrong str,size_line format");
	exit(1);
}

void		find_color(char *str, t_map *map)
{
	int		i;
	char	*s;

	i = -1;
	s = ft_strnew(0);
	while (str[++i])
		if (str[i] == ',')
		{
			s = ft_strncat(s, str, i);
			break ;
		}
	check_is_alpha(1, s);
	free(s);
	i = -1;
	while (*str != ',')
		str++;
	if (ft_strlen(str) < 4 || ft_strlen(str) > 10)
		ft_exit();
	str = str + 3;
	map->color = ft_atoi_base(str, 16);
}
