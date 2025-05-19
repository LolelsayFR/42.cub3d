NAME			=	cub3D

SRC				=	$(wildcard srcs/**/*.c)\
					$(wildcard srcs/*.c)


CFLAGS			=	-Wall -Werror -Wextra -Iheaders -g -Iinclude

LIBFT_PATH		=	./submodules/42.libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MLX_PATH	=	./submodules/MLX42
MLX_BUILD	=	$(MLX_PATH)/build
MLX_FLAGS	=	-ldl -lglfw -lm
MLX			=	$(MLX_BUILD)/libmlx42.a

all:	hello $(NAME)

OBJ		= 	${SRC:.c=.o}

hello:
	@echo "\e[48;2;100;0;100;1m Welcome to "$(NAME)" Makefile !\e[0m\n"

$(NAME): ${OBJ} ${MLX} ${LIBFT}
	git submodule update --init --recursive
	@echo "\e[48;2;0;155;0;1m Compile "$(NAME)" \e[0m\n"
	cc ${OBJ} ${CFLAGS} ${MLX_FLAGS} ${LIBFT} ${MLX} -o $(NAME)
	@echo "\e[48;2;0;0;155;1m Done \e[0m\n"

$(LIBFT):
	@echo "\e[48;2;0;155;0;1m Make $(LIBFT) \e[0m\n"
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH)
	@$(MAKE) --no-print-directory  clean  -C $(LIBFT_PATH)
	@echo "\e[48;2;0;0;155;1m Done for $(LIBFT) \e[0m\n"


$(MLX):
	@echo "\e[48;2;0;155;0;1m Make $(MLX) \e[0m\n"
	@cmake $(MLX_PATH) -B $(MLX_BUILD) && make -C $(MLX_BUILD) -s -j4
	@echo "\e[48;2;0;0;155;1m Done for $(MLX) \e[0m\n"

clean: hello
	@echo "\e[48;2;155;100;0;1m Clean "$(NAME)" dependencies \e[0m\n"
	@$(MAKE) --no-print-directory  fclean  -C $(LIBFT_PATH)
	@$(MAKE) --no-print-directory  fclean  -C $(LIBFT_PATH)
	$(RM) $(OBJ)
	$(RM) -r ${MLX_BUILD}
	@echo "\n\e[48;2;0;0;155;1m Done \e[0m\n"

fclean: hello clean
	@echo "\e[48;2;155;100;0;1m Uninstall "$(NAME)" \e[0m\n"
	$(RM) $(NAME)
	@echo "\e[48;2;0;0;155;1m Done \e[0m\n"

%.o: %.c
	cc ${CFLAGS} -c $< -o $@

re:
	+make fclean
	+make all

.PHONY: all clean fclean re
