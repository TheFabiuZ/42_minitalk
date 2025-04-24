GNL_SRC		= get_next_line.c get_next_line_utils.c
MORE_SRC	= ft_atoli.c ft_new_array.c ft_lengths.c ft_lengths_2.c \
			  ft_char_in_array.c 		ft_printarray_malloc.c		\
			  ft_calloc.c	ft_power.c	ft_sleep.c

DIR_OBJS	= objs/

GNL_SRCS	= ${addprefix ${GNL_PATH}, ${GNL_SRC}}
MORE_SRCS	= ${addprefix ${MORE_PATH}, ${MORE_SRC}}

GNL_PATH	= get_next_line/
MORE_PATH	= fts_more/

PRINTF_PATH	= ft_printf/
PRINTF		= ${PRINTF_PATH}libftprintf.a

GNL_OBJ		= ${GNL_SRC:.c=.o}
GNL_OBJS	= ${GNL_SRCS:.c=.o}
PRE_GNL_OBJS= $(addprefix ${DIR_OBJS}, ${GNL_OBJ})

MORE_OBJ	= ${MORE_SRC:.c=.o}
MORE_OBJS	= ${MORE_SRCS:.c=.o}
PRE_M_OBJS	= ${addprefix ${DIR_OBJS}, ${MORE_OBJ}}

NAME		= libft.a

GCC			= gcc

CFLAGS		= -Wall -Wextra -Werror

AR			= ar

.c.o:
			@${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${PRINTF} dup_obj ${PRE_GNL_OBJS} ${PRE_M_OBJS}
			@cp ${PRINTF} ${NAME}
			@${AR} -crs ${NAME} ${PRE_GNL_OBJS} ${PRE_M_OBJS}
			@echo -ne 'libft CREATED                    \r'
			@echo -ne '\n'

${PRINTF}:
			@make -s -C ${PRINTF_PATH} all

dup_obj:	${GNL_OBJS} ${MORE_OBJS}
			@mkdir -p ${DIR_OBJS}
			@mv ${GNL_OBJS} ${DIR_OBJS}
			@mv ${MORE_OBJS} ${DIR_OBJS}

loading:
			@echo -ne 'LOADING\033[0;5m...\r'
			@sleep 1
			@echo -ne '\033[0;32m⦗❚❚❚❚❚❚                   ⦘(25%)\r'
			@sleep 0.2
			@echo -ne '⦗❚❚❚❚❚❚❚❚❚❚❚❚❚            ⦘(50%)\r'
			@sleep 0.2
			@echo -ne '⦗❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚     ⦘(75%)\r'
			@sleep 0.2
			@echo -ne '⦗❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚⦘(100%)\033[0m\r'
			@sleep 0.2

all:		${NAME}

bonus:
			@make -s -C ${PRINTF_PATH} bonus

clean:
			@make -s -C ${PRINTF_PATH} clean
			@rm -rf ${DIR_OBJS}

fclean:		clean
			@make -s -C ${PRINTF_PATH} fclean
			@rm -f ${NAME}
			@echo -ne 'REMOVED libft.a\n'

re:			fclean all

reclean:	re
			@make -s clean

.PHONY:		all clean fclean re bonus reclean