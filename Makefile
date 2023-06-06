# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vviovi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 13:27:39 by jduval            #+#    #+#              #
#    Updated: 2023/06/05 11:40:42 by jduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	cub3D

MAKEFLAGS	+=	--no-print-directory

###############################################################################

LIBS 		=	ft mlx42 dl glfw pthread m

LIBS_TARGET =	libft/libft.a			\
				MLX42/build/libmlx42.a	\

INCLUDES	=	libft/include 			\
				MLX42/include/MLX42		\
				sources/includes		\
				/usr/lib				\

###############################################################################

BUILD_DIR 	= 	.obj

SRC_DIR		=	sources

SRCS 		=	main.c


SRCS		+=	parsing/load_map.c \
				parsing/utils_map.c \
				parsing/map_verif.c \
				parsing/content_verif.c \
				parsing/map_get_info.c \

SRCS		+=	input/key_functions.c	\

SRCS		+=	movements/move_player.c	\
				movements/shift_player.c	\
				movements/rotate_player.c	\
				movements/wall_collision.c	\

SRCS		+=	draw/draw_map.c	\
				draw/draw_player.c	\
				draw/draw_utils.c	\
				draw/draw_line.c	\
				draw/draw_texture.c	\
				draw/draw_background.c	\
				draw/render_image.c	\

SRCS		+=	initialization/init_images.c	\
				initialization/init_player.c	\
				initialization/init_tools.c		\

SRCS		+=	raycasting/raycasting.c	\
				raycasting/raycasting_utils.c	\

SRCS		:=	$(SRCS:%=$(SRC_DIR)/%)

OBJS 		:= $(SRCS:%.c=$(BUILD_DIR)/%.o)

DEPS 		:= $(OBJS:.o=.d)


###############################################################################

CC 			=	gcc

CFLAGS 		=	-Wextra -Wall -ggdb3

CPPFLAGS 	=	-MMD -MP $(addprefix -I,$(INCLUDES))

LDFLAGS		=	$(addprefix -L,$(dir $(LIBS_TARGET)))

LDLIBS		=	$(addprefix -l,$(LIBS))

DIRDUP 		= 	mkdir -p $(@D)


###############################################################################

all: $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	@$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	$(info CREATED $(NAME))

$(LIBS_TARGET):
	@$(MAKE) -C $(dir $@)

$(BUILD_DIR)/%.o : %.c
	@$(DIRDUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

-include $(DEPS) test.mk

###############################################################################

clean:
	@${MAKE} -C libft/ clean
	@${MAKE} -C MLX42/build/ clean
	rm -rf .obj
.PHONY:clean

fclean: clean
	@${MAKE} -C libft/ fclean
	@${MAKE} -C MLX42/build/ clean
	rm -f ${NAME}
.PHONY: fclean

re: fclean all
.PHONY: re
