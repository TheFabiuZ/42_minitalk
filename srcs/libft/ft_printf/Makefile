PRINTF_SRC	= ft_putnbr_nodash.c ft_char_in_array.c ft_convert_csp.c \
			  ft_convert_diuxX.c ft_exam_format.c  ft_print_hex.c ft_morelen.c \
			  ft_convert_a.c	 ft_padding.c      ft_update_tab.c ft_printf.c

DIR_OBJS	= objs/

LIBFT_PATH	= ../fts_libft
LIBFT		= ${LIBFT_PATH}/libft.a

OBJS		= ${PRINTF_SRC:.c=.o}
PRE_OBJS	= $(addprefix ${DIR_OBJS}, ${OBJS})

NAME		= libftprintf.a

GCC			= gcc

CFLAGS		= -Wall -Wextra -Werror

AR			= ar

${DIR_OBJS}%.o:	%.c libftprintf.h
			@mkdir -p ${DIR_OBJS}
			@${GCC} ${CFLAGS} -c $< -o $@

${NAME}:	${LIBFT} ${PRE_OBJS}
			@cp ${LIBFT} ${NAME}
			@${AR} -crs ${NAME} ${PRE_OBJS}
			@echo -ne 'ft_printf READY\r'
			@echo -ne '\n'

${LIBFT}:
			@make -s -C ${LIBFT_PATH} all

all:		${NAME}

bonus:
			@make -s -C ${LIBFT_PATH} bonus

clean:
			@make -s -C ${LIBFT_PATH} clean
			@rm -rf ${DIR_OBJS}

fclean:		clean
			@make -s -C ${LIBFT_PATH} fclean
			@rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
