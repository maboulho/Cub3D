/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3er.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:22:55 by atouati           #+#    #+#             */
/*   Updated: 2023/02/01 18:37:35 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3ER_H
# define CUB3ER_H

# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "mlx.h"
# include <math.h> 
# include <limits.h>
# include "./parsing/cube.h"
# define TILESISE 50

typedef struct s_ray
{
	double	ray_angle;
	double	wall_hit_x;
	double	wall_hit_y;
	double	distance;
	int		wall_hit_virt;
	int		ray_up;
	int		ray_down;
	int		ray_left;
	int		ray_right;
	int		wall_hit_content;	
	int		top_wall;
	int		bottom_wall;
	double	horzwallhitx;
	double	horzwallhity;
	double	vertwallhitx;
	double	vertwallhity;
	int		foundhorzwallhit;
	int		foundvertwallhit;
	double	xintercept;
	double	yintercept;
	double	xstep;
	double	ystep;
	int		wall_hieght;
	int		offset_x;
	int		offset_y;
	int		ray;
}	t_ray;

typedef struct s_mini {
	int	j;
	int	i;
	int	h;
	int	v;
	int	a;
	int	b;
}	t_mini;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}				t_data;
typedef struct address
{
	t_data	no;
	t_data	so;
	t_data	we;
	t_data	ea;
}			t_address;

typedef struct s_vars
{
	t_cube		*map;
	void		*mlx;
	void		*mlx_win;
	void		*img;
	double		x;
	double		y;
	double		angle;
	int			num_row;
	int			num_col;
	int			turn_direction;
	int			move_direction;
	double		move_speed;
	double		turn_speed;
	int			num_ray;
	double		step;
	t_ray		rays;
	t_data		data;
	t_address	tex;
	int			left_rigth_direction;
	double		step_r_l;
	int			move_x;
	int			turn_mouse;
	int			flag;
}	t_vars;

void		init_var(t_vars *vr);
int			button_release(int button, int x, int y, void *ptr);
int			button_mouse(int x, int y, void *ptr);
int			button_press(int button, int x, int y, void *ptr);
int			mouse_hook(int mouse);
int			press_key(int keycode, void *ptr);
int			release_key(int keycode, void *ptr);
void		execution(t_vars *p);
t_ray		*cast_rays(t_vars *vr, t_ray *rays);
void		get_image_addr(t_vars *vr);
void		drow_ceil_floo(t_ray *rays, t_vars *vr, int ray);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		distance(t_vars *vr, t_ray *rays, int ray);
void		cast_vert(t_vars *vr, t_ray *rays, int ray);
void		cast_horz(t_vars *vr, t_ray *rays, int ray);
void		wall_hieght(t_vars *vr, t_ray *rays, int ray);
void		put_wall_ea(t_vars *vr, t_ray *rays, int i, t_address *textures);
void		put_wall_no(t_vars *vr, t_ray *rays, int i, t_address *textures);
void		put_wall_we(t_vars *vr, t_ray *rays, int i, t_address *textures);
void		put_wall_so(t_vars *vr, t_ray *rays, int i, t_address *textures);
void		move_position(t_vars *vr);
void		rendering_map(t_vars *vr);
int			get_the_height(char **str);
int			get_the_width(char **str);
void		init(t_ray *rays, int ray);
double		norm_angle(double ray_angle);
void		get_player_angle(t_vars *vr);
void		clear_win(t_vars *vr);
int			has_wall(double x, double y, t_vars *vr);
void		put_mini_wall(t_vars *vr, t_mini *mini);
void		put_mini_floor(t_vars *vr, t_mini *mini);

#endif