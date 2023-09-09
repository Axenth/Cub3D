NAME = cub3D

SUPRESS_MLX ?= > /dev/null

SRC = main.c key.c draw.c camera.c ray.c map.c \
	  player_movement.c error_handeling.c parser/resolution.c \
	  parser/floor_ceiling_color.c parser/player_position.c \
	  screenshot/bitmap_header.c parser/enclosed_map.c \
	  safety.c map2.c parser/enclosed_map_2.c draw_sprites.c \
	  calc_draw.c set_textures.c rotation.c \
	  map3.c parser/verification.c screenshot/bitmap_safety.c \
	  init.c sort_sprites.c load_images.c safety2.c

SRC_MAP = srcs/

SRCS = $(addprefix $(SRC_MAP), $(SRC))

LIBS = libft/libft.a

HDRS = -I libft/hdrs -I hdrs/

OBJS := $(SRCS:.c=.o)

OPT_FLAGS = -O2

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
LIBS += libmlx.a
HDRS += -I mlx_linux/
endif
ifeq ($(UNAME_S),Darwin)
LIBS += libmlx.dylib
HDRS += -I mlx/
endif

all: $(NAME)

ifeq ($(UNAME_S),Linux)
$(NAME): $(OBJS)
	@echo ""
	@$(MAKE) -C libft/ all
	@$(MAKE) -C mlx_linux/ $(SUPRESS_MLX)
	@mv mlx_linux/libmlx.a ./libmlx.a
	@clang -o $@ $^ $(LIBS) $(HDRS) -lm -g \
	-Wall -Werror -Wextra -Ofast -lXext -lX11 -lm
	@echo "Creating $@"
endif
	
ifeq ($(UNAME_S),Darwin)
$(NAME): $(OBJS)
	@echo ""
	@$(MAKE) -C  libft/ all
	@$(MAKE) -C mlx/ all $(SUPRESS_MLX)
	@mv mlx/libmlx.dylib ./libmlx.dylib
	@clang -o $@ $^ $(LIBS) $(HDRS) -lm -Lmlx -framework OpenGL \
	-framework AppKit -lm -g -Wall -Werror -Wextra  -Ofast
	@echo "Creating $@"
endif



%.o: %.c
	@clang -o $@ -c $<  $(HDRS) -Wall -Werror -Wextra -Ofast
	@echo -n "\033[2K \rCC $@"

clean: 
	@echo "Cleaning"
	@$(MAKE) -C libft/ clean
	@$(MAKE) -C mlx/ clean
	@rm $(OBJS)

fclean: 
	@echo "Cleaning"
	@$(MAKE) -C libft/ fclean
	@$(MAKE) -C mlx/ clean
	@rm -f $(OBJS)
	@rm -f libmlx.dylib
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
