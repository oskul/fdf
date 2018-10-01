/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:57:17 by oskulska          #+#    #+#             */
/*   Updated: 2018/03/27 15:57:26 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H
# include <fcntl.h>
# include "libft/libft.h"
# include <math.h>
# include <mlx.h>
# define W_X 1000
# define W_Y 1000

typedef	struct		s_map
{
	double			x;
	double			y;
	double			z;
	int				color;
	struct s_map	*next;
}					t_map;

typedef struct		s_brz
{
	int				x0;
	int				x1;
	int				y0;
	int				y1;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e;
}					t_brz;

typedef	struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				deg;
	int				size_line;
	int				*str;
	double			zoom;
	int				max_x;
	int				max_y;
	int				max_z;
	int				flag;
	int				ret;
	int				len;
	int				flag_read;
	t_map			*begin;
	t_brz			*brz;
}					t_mlx;

t_map				*init_map();
t_mlx				*init_mlx();
void				find_color(char *str, t_map *map);
void				ft_clear(char **arr, char *line);
int					ft_check(char c);
int					ft_pow(int nbr, int pow);
void				check_len(int x, int y, t_mlx *mlx, char **str);
int					count_len(char **str);
void				rotate(t_mlx *mlx, double a, double b, double c);
void				read_map(int fd, t_mlx *mlx, int y, int x);
void				find_cord(t_map *map, int x, int y, char *str);
void				find_new_cord(t_mlx *mlx);
void				free_data(t_mlx *mlx);
void				line(t_map *tmp, t_map *temp, t_mlx *mlx);
void				put_pixel(int x, int y, t_mlx *mlx, int color);
void				img_init(t_mlx *mlx);
void				print(t_mlx *mlx);
int					key_hook(int keycode, t_mlx *mlx);
void				new_scale(t_mlx *mlx, float a);
void				exit_free();
#endif
