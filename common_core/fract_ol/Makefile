# Name of the program
NAME = fract_ol

# Name of libft (with ft_printf)
PRINTF_PATH = ./ft_printf
NAMEPRINTF = $(PRINTF_PATH)/libftprintf.a

# Compiler
CC = cc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -L$(PRINTF_PATH) -lftprintf

# Remove
RM = rm -f

# Minilibx
MLX_PATH	= mlx/
NAMEMLX	= libmlx.a
MLX			= $(MLX_PATH)$(NAMEMLX)

# Detect OS
UNAME := $(shell uname)

# OS-Specific Configurations
ifeq ($(UNAME), Darwin)  # macOS
    MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
else  # Linux
    MLX_FLAGS = -Lmlx -lmlx -lXext -lX11 -lm
endif

# Includes
INC	=	-I ./includes \
		-I ./ft_printf \
		-I ./ft_printf/libft \
		-I ./mlx

# Sources
SRCS_PATH = ./srcs
SRCS_PRINTF := $(wildcard $(PRINTF_PATH)/*.c)
SRCS := $(wildcard $(SRCS_PATH)/*.c)

OBJS_PRINTF = ${SRCS_PRINTF:.c=.o}
OBJS = ${SRCS:.c=.o}

all:	$(NAME)

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@ $(INC)

$(NAME): $(OBJS) $(NAMEPRINTF) $(MLX)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(INC) $(MLX_FLAGS)

$(NAMEMLX):
	@make -C $(MLX_PATH)

$(NAMEPRINTF):
	@make -C $(PRINTF_PATH)

clean:
	${RM} ${OBJS}
	@cd $(PRINTF_PATH) && make clean

fclean: clean
	${RM} ${OBJS} ${NAME}
	@cd $(PRINTF_PATH) && make fclean

re: fclean all

.PHONY: all clean fclean re
