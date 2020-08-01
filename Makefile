NAME = cub3D

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

LIBS = libft/libft.a libmlx.dylib

HDRS = -I mlx -I libft/hdrs -I hdrs/

OBJS := $(SRCS:.c=.o)

OPT_FLAGS = -O2

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C  libft/ all
	@$(MAKE) -C mlx/ all
	mv mlx/libmlx.dylib ./libmlx.dylib
	clang -o $@ $^ $(LIBS) $(HDRS) -lm -Lmlx -framework OpenGL \
	-framework AppKit -lm -g -Wall -Werror -Wextra  -Ofast

%.o: %.c
	clang -o $@ -c $<  $(HDRS) -Wall -Werror -Wextra -Ofast

clean: 
	@$(MAKE) -C libft/ clean
	@$(MAKE) -C mlx/ clean
	rm $(OBJS)

fclean: 
	@$(MAKE) -C libft/ fclean
	@$(MAKE) -C mlx/ clean
	rm -f $(OBJS)
	rm -f libmlx.dylib
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
