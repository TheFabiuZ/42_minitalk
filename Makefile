SERVER_SRC		= server.c

CLIENT_SRC		= client.c

SERVER_SRCS		= ${addprefix ${PRE}, ${SERVER_SRC}}
CLIENT_SRCS		= ${addprefix ${PRE}, ${CLIENT_SRC}}

DIR_OBJS		= objs/

PRE				= srcs/

LIBFT_PATH		= ${PRE}libft/
LIBFT			= ${LIBFT_PATH}libft.a

SERVER_OBJ		= ${SERVER_SRC:.c=.o}
SERVER_OBJS		= ${SERVER_SRCS:.c=.o}
SERVER_PRE_OBJS	= ${addprefix ${DIR_OBJS}, ${SERVER_OBJ}}
CLIENT_OBJ		= ${CLIENT_SRC:.c=.o}
CLIENT_OBJS		= ${CLIENT_SRCS:.c=.o}
CLIENT_PRE_OBJS	= ${addprefix ${DIR_OBJS}, ${CLIENT_OBJ}}

CLIENT_NAME		= client

SERVER_NAME		= server

GCC				= gcc

CFLAGS			= -Wall -Werror -Wextra

all:			$(CLIENT_NAME) $(SERVER_NAME)

.c.o:
				@${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(CLIENT_NAME):	${LIBFT} ${CLIENT_OBJS} dup_obj_client ${CLIENT_PRE_OBJS} loading
				@$(GCC) $(CFLAGS) -o $(CLIENT_NAME) $(CLIENT_PRE_OBJS) ${LIBFT}
				@echo -ne 'CLIENT READY                           \r\n'

$(SERVER_NAME): ${LIBFT} ${SERVER_OBJS} dup_obj_server ${SERVER_PRE_OBJS} loading
				@$(GCC) $(CFLAGS) -o $(SERVER_NAME) $(SERVER_PRE_OBJS) ${LIBFT}
				@echo -ne 'SERVER READY                           \r\n'

${LIBFT}:
				@make -s -C ${LIBFT_PATH} all

dup_obj_client:
				@mkdir -p ${DIR_OBJS}
				@mv ${CLIENT_OBJS} ${DIR_OBJS}

dup_obj_server:
				@mkdir -p ${DIR_OBJS}
				@mv ${SERVER_OBJS} ${DIR_OBJS}

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

bonus:			all

clean:
				@make -s -C ${LIBFT_PATH} clean
				@rm -rf $(DIR_OBJS)
				@echo -ne 'REMOVED OBJS\n'

fclean:			clean
				@make -s -C ${LIBFT_PATH} fclean
				@rm -f $(CLIENT_NAME) $(SERVER_NAME)
				@echo -ne 'CLIENT/SERVER UNINSTALLED\n'

re:				fclean all

reclean:		re
				@make -s clean

.PHONY			= all clean fclean re reclean $(CLIENT_NAME) $(SERVER_NAME) bonus