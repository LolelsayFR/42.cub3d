NAME		:= 	cub3D

SRC			:= 	srcs/main.c\
				srcs/exec/door_using.c\
				srcs/exec/game.c\
				srcs/exec/minimap.c\
				srcs/exec/player/control_handler.c\
				srcs/exec/player/player_control.c\
				srcs/exec/player/player_init.c\
				srcs/exec/raycasting/raycasting.c\
				srcs/exec/raycasting/ray_colider.c\
				srcs/exec/raycasting/ray_utils.c\
				srcs/exec/raycasting/texture_apply.c\
				srcs/mapping/convert_map.c\
				srcs/mapping/errors.c\
				srcs/mapping/free_data.c\
				srcs/mapping/inits.c\
				srcs/mapping/map_verif.c\
				srcs/mapping/doors_stocking.c\
				srcs/mapping/finds.c\
				srcs/mapping/init_data.c\
				srcs/mapping/mapping.c\
				srcs/mapping/separ_value.c\
				srcs/utils/create_rgb.c\
				srcs/utils/ft_tablen.c\
				srcs/utils/intlen.c\
				srcs/utils/map_size.c\
				srcs/utils/mlx_img_utils.c\
				srcs/utils/print_tab.c\
				srcs/utils/fixed_mouse_mlx.c\
				srcs/utils/get_door_data.c\
				srcs/utils/lst_to_tab.c\
				srcs/utils/math_trigo.c\
				srcs/utils/pos_to_map_pos.c

OBJ		= 	${SRC:.c=.o}

CFLAGS		:=	-Wall -Werror -Wextra -g -Iheaders -O3
LIBFT_PATH	:=	./submodules/42.libft
LIBFT		:=	$(LIBFT_PATH)/libft.a

MLX_PATH	:=	./submodules/minilibx-linux
MLX_FLAGS	:=	-lXext -lX11 -lm -lXfixes
MLX			:=	$(MLX_PATH)/libmlx.a

.PHONY: all clean fclean re
all: hello $(NAME)

hello:
	@echo "\e[48;2;100;0;100;1m Welcome to $(NAME) Makefile !\e[0m\n"

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	@echo "\e[48;2;0;155;0;1m Compile $(NAME) \e[0m\n"
	cc $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)
	@echo "\e[48;2;0;0;155;1m Done \e[0m\n"

potato:
	+make fclean
	+make $(LIBFT) $(MLX)
	+make $(NAME) CFLAGS+=" -D POTATO=1 -Wall -Werror -Wextra -g -Iheaders -O3"

$(LIBFT):
	git submodule update --init --recursive
	@echo "\e[48;2;0;155;0;1m Make $(LIBFT) \e[0m\n"
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH)
	@echo "\e[48;2;0;0;155;1m Done for $(LIBFT) \e[0m\n"

$(MLX):
	git submodule update --init --recursive
	@echo "\e[48;2;0;155;0;1m Make $(MLX) \e[0m\n"
	@$(MAKE) --no-print-directory -C $(MLX_PATH)
	@echo "\e[48;2;0;0;155;1m Done for $(MLX) \e[0m\n"

clean:
	@echo "\e[48;2;155;100;0;1m Clean $(NAME) dependencies \e[0m\n"
	@$(MAKE) --no-print-directory clean -C $(LIBFT_PATH)
	@$(MAKE) --no-print-directory clean -C $(MLX_PATH)
	$(RM) -r $(OBJ)
	@echo "\n\e[48;2;0;0;155;1m Done \e[0m\n"

fclean: clean
	@echo "\e[48;2;155;100;0;1m Uninstall $(NAME) \e[0m\n"
	$(RM) $(NAME)
	@echo "\e[48;2;0;0;155;1m Done \e[0m\n"

%.o: %.c
	cc ${CFLAGS} -c $< -o $@

re:
	+make fclean
	+make all
