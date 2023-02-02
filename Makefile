# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 05:36:02 by atouati           #+#    #+#              #
#    Updated: 2023/02/02 03:55:32 by maboulho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D

CC = cc

C_FLAGS = -Wall -Wextra -Werror -fsanitize=address -g

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit


FUNCTIONS =	main.c\
			./Cub3er-Execution/angle.c\
			./Cub3er-Execution/cast_horz.c\
			./Cub3er-Execution/cast_rays.c\
			./Cub3er-Execution/cast_vert.c\
			./Cub3er-Execution/clear.c\
			./Cub3er-Execution/cub3d.c\
			./Cub3er-Execution/distance.c\
			./Cub3er-Execution/drow_ceil_floo.c\
			./Cub3er-Execution/get_image_addr.c\
			./Cub3er-Execution/get_width_heigth.c\
			./Cub3er-Execution/hooks.c\
			./Cub3er-Execution/init.c\
			./Cub3er-Execution/move_position.c\
			./Cub3er-Execution/my_mlx_pixel_put.c\
			./Cub3er-Execution/put_mini.c\
			./Cub3er-Execution/put_wall.c\
			./Cub3er-Execution/rendering_map.c\
			./Cub3er-Execution/wall_hieght.c\
			./parsing/get_next_line.c\
			./parsing/get_next_line_utils.c\
			./parsing/ft_split.c\
			./parsing/parsing_utils.c\
			./parsing/parsing_utils1.c\
			./parsing/parsing_utils2.c\
			./parsing/parsing_utils3.c\
			./parsing/rgb_color_c.c\
			./parsing/rgb_color_f.c\
			./parsing/check_real_map.c\
			./parsing/check_real_map2.c\
			./parsing/parsing_utils4.c\
			./parsing/parsing_utils5.c\
			./parsing/parsing_utils6.c\
			./parsing/check_real_map3.c\
		
RM = rm -rf

all		:	$(NAME) 

$(NAME) : $(FUNCTIONS)
			$(CC) $(C_FLAGS) $(FUNCTIONS) $(MLX_FLAGS)  -o $(NAME) 

clean	:	
			$(RM) $(NAME)
			
fclean	:	clean
re 		:	fclean all