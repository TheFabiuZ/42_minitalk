LIBFT_SRC	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			  ft_strlen.c  ft_memset.c  ft_bzero.c   ft_memcpy.c  ft_memmove.c \
			  ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			  ft_strrchr.c ft_strncmp.c ft_memchr.c  ft_memcmp.c  ft_strnstr.c \
			  ft_atoi.c    ft_calloc.c  ft_strdup.c  ft_strmapi.c ft_substr.c \
			  ft_strjoin.c ft_strtrim.c ft_split.c   ft_itoa.c   ft_striteri.c \
			  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

LIBFT_SRC_B	= ft_lstnew.c ft_lstdelone.c ft_lstclear.c ft_lstadd_front.c \
			  ft_lstadd_back.c ft_lstsize.c ft_lstiter.c ft_lstmap.c \
			  ft_lstlast.c

DIR_OBJS	= objs/

OBJS		= ${LIBFT_SRC:.c=.o}
PRE_OBJS	= $(addprefix ${DIR_OBJS}, ${OBJS})

OBJS_B		= ${LIBFT_SRC_B:.c=.o}
PRE_OBJS_B	= $(addprefix ${DIR_OBJS}, ${OBJS_B})

NAME		= libft.a

GCC			= gcc

CFLAGS		= -Wall -Wextra -Werror

AR			= ar

${DIR_OBJS}%.o : %.c libft.h
			@mkdir -p ${DIR_OBJS}
			@${GCC} ${CFLAGS} -c $< -o $@

${NAME}:	${PRE_OBJS}
			@echo -ne 'libft.a READY\r'
			@echo -ne '\n'
			@${AR} -crs ${NAME} ${PRE_OBJS}

all:		${NAME}

bonus:		${PRE_OBJS} ${PRE_OBJS_B}
			@echo -ne '\nfts_libft.a + bonus CREATED\r'
			@echo -ne '\n'
			@${AR} -crs ${NAME} ${PRE_OBJS} ${PRE_OBJS_B}

clean:
			@rm -rf ${DIR_OBJS}

fclean: 	clean
			@echo -ne 'REMOVED fts_libft.a\n'
			@rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
