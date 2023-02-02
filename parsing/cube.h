/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 00:05:28 by maboulho          #+#    #+#             */
/*   Updated: 2023/02/02 04:07:56 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# define BUFFER_SIZE 1

typedef struct s_cube
{
	char	*no;
	int		start;
	int		end;
	int		j;
	char	*so;
	char	*ea;
	char	*we;
	char	**map;
	char	*cc;
	char	*fc;
	int		c_final;
	int		f_final;
	int		e;
	int		w;
	int		s;
	int		n;
	int		f;
	int		c;
	char	**cube_map1;
	char	**cube_map;
	int		last_line;
	int		*texture;
	int		index;
	int		lenght;
	int		six;
	char	**f_rgb;
	char	**c_rgb;
	char	direction;
	int		x;
	int		y;
	int		tab_c[3];
	int		tab_f[3];
}			t_cube;

void	init_values2(t_cube *p);
void	check_real_map2(t_cube *p, int i, int j, int ind);
int		check_space_last(char *s);
void	new_map2(t_cube *p, int lenght, int i, int j);
int		get_width(char **s);
void	new_map(t_cube *p);
void	check_last_line(char *s);
void	error_blank(void);
t_cube	*parse(char **av);
char	*get_next_line(int fd);
void	check_map_error(t_cube *p);
void	check_duplicates(char **s);
void	flagino(int flag);
void	check_zero(char **s, t_cube *p);
void	check_real_map(t_cube *p);
void	check_real_map(t_cube *p);
char	*ft_substr(char const *s, unsigned int start, unsigned int len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
void	get_north(t_cube *p, char *s);
void	get_rgb(t_cube *p);
void	check_map_values(t_cube *p);
int		get_c_rgb(t_cube *p);
int		get_f_rgb(t_cube *p);
void	get_east(t_cube *p, char *s);
void	get_south(t_cube *p, char *s);
void	get_west(t_cube *p, char *s);
void	check_map(t_cube *p, char **av);
int		map_lenght(int fd, char *s);
void	cub_to_2d(t_cube *p, char *s);
void	texture_check(t_cube *p);
int		ft_atoi(const char *str);
void	init_values(t_cube *p);
void	check_befor_map(t_cube *p);
int		check_first_line(char *s);
int		check_spaces(char *s);
void	create_so(t_cube *p, int i);
void	create_ea(t_cube *p, int i);
void	create_no(t_cube *p, int i);
void	create_we(t_cube *p, int i);
void	create_f(t_cube *p, int i);
void	create_c(t_cube *p, int i);
char	*ft_substr1(char *s, int start, int len);
void	check_rgb(t_cube *p);
int		ft_isdigit(int c);
int		ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
void	rgb_error(void);
void	creat_f_part(t_cube *p);
void	check_f_rgb(t_cube *p);
void	creat_c_part(t_cube *p);
void	check_c_rgb(t_cube *p);
int		check_only_spaces(char *s, int i);
void	check_comma_plus(char *s);
int		check_chars(char *s);
void	check_zero2(char **s, int i, int j);
void	check_player(char **s, int i, int j);
void	check_map_values2(t_cube *p, int i, int j);
void	init_map_values2(t_cube *p, int i, int j);
void	error_textures(void);
int		lenght(int fd, char *s);
void	init_map_values(t_cube *p);
int		ft_strchr2(char *str, int c);
int		ft_strlen2(char	*s);
int		ft_len(char **s);
int		longest_str(char **s);
void	check_xpm(char *s);
void	open_xpm(char *s);
#endif