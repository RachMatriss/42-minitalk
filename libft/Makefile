# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 11:34:34 by ramedjra          #+#    #+#              #
#    Updated: 2023/02/17 11:08:11 by ramedjra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_atoi.c ft_isalpha.c  ft_itoa.c ft_strjoin.c ft_memmove.c\
				ft_putnbr_fd.c  ft_memcpy.c ft_strlcpy.c ft_striteri.c ft_tolower.c\
				ft_bzero.c ft_isascii.c ft_memchr.c  ft_memset.c ft_putstr_fd.c\
				ft_strlen.c ft_strrchr.c ft_toupper.c ft_strnstr.c ft_calloc.c\
				ft_isdigit.c ft_memcmp.c ft_putchar_fd.c ft_split.c ft_printf.c \
				ft_strmapi.c ft_strtrim.c ft_isalnum.c ft_isprint.c ft_strdup.c\
				ft_putendl_fd.c ft_strchr.c ft_strlcat.c ft_strncmp.c ft_substr.c get_next_line.c
OBJS 			= $(SRCS:.c=.o)

BONUS		=	ft_lstadd_front.c  ft_lstdelone.c  ft_lstlast.c  ft_lstnew.c\
				ft_lstadd_back.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstsize.c
BONUS_OBJS		= $(BONUS:.c=.o)

CC 				= gcc 
RM 				= rm -f 
CFLAGS			= -Wall -Wextra -Werror -I.

NAME 			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:   
				@$(RM)  $(OBJS) $(BONUS_OBJS)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean all
	
bonus:			@$(OBJS) $(BONUS_OBJS)
				@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
				
.PHONY:			all clean fclean re bonus