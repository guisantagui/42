# Name of the program
NAME = fract_ol

# Name of libft (with ft_printf)
PRINTF_PATH = ./ft_printf
NAMEPRINTF = $(PRINTF_PATH)/libftprintf.a

# Compiler
CC = cc
CFLAGS = -Wall -Werror -Wextra -DGL_SILENCE_DEPRECATION
LDFLAGS = -L$(PRINTF_PATH) -lftprintf

# Remove
RM = rm -f

# Minilibx
MLX_PATH	= mlx/
NAMEMLX	= libmlx.a
MLX			= $(MLX_PATH)$(NAMEMLX)

# Detect OS
UNAME := $(shell uname)

# Includes
INC	=	-I ./includes \
		-I ./ft_printf \
		-I ./ft_printf/libft

NAMEMLX = libmlx.a

# OS-Specific Configurations
ifeq ($(UNAME), Darwin)  # macOS
    MLX_PATH = ./mlx_opengl/
    MLX      = $(MLX_PATH)$(NAMEMLX)
    MLX_FLAGS = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
    INC += -I ./keys_mac \
	   -I ./mlx_opengl
else  # Linux
    MLX_PATH = ./mlx_linux/
    MLX      = $(MLX_PATH)$(NAMEMLX)
    MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm
    INC += -I ./keys_linux \
	   -I ./mlx_linux
endif

# Minilibx
NAMEMLX = libmlx.a
MLX                     = $(MLX_PATH)$(NAMEMLX)

# Sources
SRCS_PATH = ./srcs
SRCS_PRINTF := $(wildcard $(PRINTF_PATH)/*.c)
SRCS := $(wildcard $(SRCS_PATH)/*.c)

OBJS_PRINTF = ${SRCS_PRINTF:.c=.o}
OBJS = ${SRCS:.c=.o}

all:	$(NAME)

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@ $(INC)

$(NAME): $(OBJS) $(NAMEPRINTF) $(NAMEMLX)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(INC) $(MLX_FLAGS)

$(NAMEMLX):
	@make -C $(MLX_PATH)

$(NAMEPRINTF):
	@make -C $(PRINTF_PATH)

clean:
	${RM} ${OBJS}
	@cd $(PRINTF_PATH) && make clean
	@make -C $(MLX_PATH) clean

fclean: clean
	${RM} ${OBJS} ${NAME}
	@cd $(PRINTF_PATH) && make fclean
	@make -C $(MLX_PATH) clean

re: fclean all

.PHONY: all clean fclean re
