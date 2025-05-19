NAME		:= 	cub3D

SRC			:= 	$(wildcard srcs/*.c)\
				$(wildcard srcs/**/*.c)\
				$(wildcard srcs/**/**/*.c)\


OBJDIR		:=	.objs
OBJS		:=	$(patsubst srcs/%.c,$(OBJDIR)/%.o,$(SRC))

CFLAGS		:=	-Wall -Werror -Wextra -g -Iheaders
LIBFT_PATH	:=	./submodules/42.libft
LIBFT		:=	$(LIBFT_PATH)/libft.a

MLX_PATH	:=	./submodules/minilibx-linux
MLX_FLAGS	:=	-lXext -lX11 -lXpm -lm
MLX			:=	$(MLX_PATH)/libmlx.a

.PHONY: all clean fclean re
all: hello $(NAME)


hello:
	@echo "\e[48;2;100;0;100;1m Welcome to $(NAME) Makefile !\e[0m\n"
	@echo "\e[48;2;100;0;0;1m Welcome to THE BIG WILDCARD !\e[0m\n"

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	@echo "\e[48;2;0;155;0;1m Compile $(NAME) \e[0m\n"
	cc $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)
	@echo "\e[48;2;0;0;155;1m Done \e[0m\n"

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

$(OBJDIR)/%.o: srcs/%.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	cc $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	@echo "\e[48;2;155;100;0;1m Clean $(NAME) dependencies \e[0m\n"
	@$(MAKE) --no-print-directory clean -C $(LIBFT_PATH)
	@$(MAKE) --no-print-directory clean -C $(MLX_PATH)
	$(RM) -r $(OBJDIR)
	@echo "\n\e[48;2;0;0;155;1m Done \e[0m\n"

fclean: clean
	@echo "\e[48;2;155;100;0;1m Uninstall $(NAME) \e[0m\n"
	$(RM) $(NAME)
	@echo "\e[48;2;0;0;155;1m Done \e[0m\n"

re:
	+make fclean
	+make all