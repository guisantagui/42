SRCS = ft_memset.c \
	   ft_bzero.c \
	   ft_calloc.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strlen.c \
	   ft_strlcat.c \
	   ft_strlcpy.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strncmp.c \
	   ft_atoi.c \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strdup.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_split.c \
	   ft_strnstr.c \
	   ft_striteri.c

SRCS_B = ft_lstnew.c \
		 ft_lstadd_front.c \
		 ft_lstsize.c \
		 ft_lstlast.c \
		 ft_lstadd_back.c \
		 ft_lstdelone.c \
		 ft_lstiter.c \
		 ft_lstmap.c \
		 ft_lstclear.c

OBJS = ${SRCS:.c=.o}

OBJS_B = ${SRCS_B:.c=.o}

NAME = libft.a

CC = cc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

.c.o:	
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

bonus:		${OBJS} ${OBJS_B}
			ar rc ${NAME} ${OBJS} ${OBJS_B}
			ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS} ${OBJS_B}

fclean:		clean
			${RM} ${NAME}

re:			fclean bonus

.PHONY: bonus all clean fclean re
