
CLIENT		= client
SERVER		= server
CLIENT_BONUS	= client_bonus
SERVER_BONUS	= server_bonus
LIBFT		= libft

SERV_FILE = ./src/server.c
CLIN_FILE = ./src/client.c
SERV_BONUS_FILE = ./src/server_bonus.c
CLIN_BONUS_FILE = ./src/client_bonus.c

LIBFT_DIR  = ./libft
LIBFT = ./libft/libft.a

SRC_DIR		= src/
CC		= gcc
FLAGS		= -Wall -Werror -Wextra

AR			= ar -rc

# ${NAME}:	${SUBDIR} ${OBJS}
#			cp libft/libft.a .
#			mv libft.a ${NAME}
#			${AR} ${NAME} ${OBJS}

all: $(SERVER) $(CLIENT) 

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER): $(LIBFT)
	cc $(FLAGS) $(SERV_FILE) $(LIBFT) -o $(SERVER) 
$(CLIENT): $(LIBFT)	
	cc $(FLAGS)  $(CLIN_FILE) $(LIBFT) -o $(CLIENT)

$(SERVER_BONUS): $(LIBFT)
	cc $(FLAGS) $(SERV_BONUS_FILE) $(LIBFT) -o $(SERVER_BONUS) 
$(CLIENT_BONUS): $(LIBFT)	
	cc $(FLAGS) $(CLIN_BONUS_FILE) $(LIBFT) -o $(CLIENT_BONUS)

$(LIBFT):
	@make -C $(LIBFT_DIR)

#${SUBDIR}:
#			cd libft && make

clean:
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all bonus

.PHONY: all clean fclean re
